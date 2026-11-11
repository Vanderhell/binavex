# Performance and memory

## Current ESP32-S3 validation (2026-11-11)

Fresh validation ran on the designated COM37 ESP32-S3, revision 0.2, MAC `3c:0f:02:d9:77:30`, 40 MHz crystal, with the CPU confirmed at 240 MHz. ESP-IDF 5.5.1 and Xtensa GCC 14.2.0 built the production sources as C99 with `-O3`. The uploaded test app was 211,904 bytes (`0x33BC0`); esptool verified the image hash at app0 offset `0x10000`. Firmware printed `BINAVEX_ALL37_PASS|passed=37/37|first_failed_api=0` and completed all 37 direct API checks. No watchdog warning appeared in this final run.

Each API was measured twice, on one representative input and one boundary input. For each case the firmware took 21 samples of 1,000 calls. It subtracted a paired no-op function-pointer batch, then reported median and observed minimum/maximum cycles per call. The no-op batch median was 34,002 cycles per 1,000 calls. A volatile function pointer and result sink prevent call elimination. The measured timing includes call and harness costs not canceled by the no-op pair; it is an estimate for this exact build and board, not a portable WCET guarantee. `min..max` below combines the observed ranges from both input classes.

| API | Representative median | Boundary median | Observed min..max |
|---|---:|---:|---:|
| `pc_bit_byte_reverse_u32` | 45.00 | 45.00 | 43.55..46.23 |
| `pc_bit_deinterleave4_u32` | 59.00 | 59.00 | 57.58..60.55 |
| `pc_bit_error_syndrome_u32` | 655.03 | 655.01 | 655.00..656.49 |
| `pc_bit_extract_u64` | 71.00 | 61.00 | 59.55..72.68 |
| `pc_bit_gather_u32` | 190.00 | 366.00 | 188.58..367.49 |
| `pc_bit_interleave4_u32` | 58.00 | 58.00 | 58.00..59.49 |
| `pc_bit_nibble_reverse_u32` | 25.00 | 25.00 | 23.58..25.43 |
| `pc_bit_pair_reverse_u32` | 14.00 | 14.00 | 12.59..15.42 |
| `pc_bit_reverse_u64` | 63.00 | 63.00 | 63.00..64.49 |
| `pc_bit_scatter_u32` | 206.00 | 398.00 | 206.00..399.49 |
| `pc_bit_shuffle_even_odd_u32` | 42.00 | 42.00 | 40.59..43.49 |
| `pc_bit_swap_u32` | 43.00 | 39.00 | 38.90..44.49 |
| `pc_bit_unshuffle_even_odd_u32` | 43.00 | 43.00 | 43.00..44.42 |
| `pc_bitset_count_ones_u32` | 27.00 | 27.00 | 25.59..27.43 |
| `pc_bitset_rotate_left_u32` | 11.00 | 11.00 | 9.87..12.45 |
| `pc_clz_u64` | 34.00 | 12.00 | 10.55..35.49 |
| `pc_ctz_u64` | 37.00 | 12.00 | 11.90..38.30 |
| `pc_deinterleave_nibbles_u32` | 33.00 | 33.00 | 33.00..34.45 |
| `pc_even_parity_insert_u32` | 30.00 | 30.00 | 28.59..31.48 |
| `pc_gray_decode_u64` | 34.00 | 34.00 | 33.90..35.49 |
| `pc_gray_encode_u64` | 13.00 | 13.00 | 12.90..14.45 |
| `pc_interleave_bytes_u32` | 17.00 | 17.00 | 15.55..18.49 |
| `pc_interleave_nibbles_u32` | 33.00 | 33.00 | 31.58..33.79 |
| `pc_mask_between_u32` | 37.00 | 37.00 | 35.55..37.57 |
| `pc_mask_count_runs_u32` | 30.00 | 30.00 | 29.91..31.92 |
| `pc_mask_is_contiguous_u32` | 15.00 | 15.00 | 13.55..16.41 |
| `pc_mask_low_u64` | 38.00 | 28.00 | 28.00..39.45 |
| `pc_mask_lowest_n_u32` | 26.00 | 26.00 | 25.72..27.49 |
| `pc_parity_strip_check_u32` | 32.00 | 32.00 | 30.59..33.45 |
| `pc_parity_u64` | 31.00 | 31.00 | 31.00..32.49 |
| `pc_popcount_u64` | 48.00 | 48.00 | 47.91..49.56 |
| `pc_rotate_left_u64` | 46.00 | 46.00 | 45.90..47.42 |
| `pc_secded_parity_u32` | 381.00 | 381.00 | 379.60..382.49 |
| `pc_swap_bitpairs_u32` | 15.00 | 15.00 | 15.00..16.42 |
| `pc_swap_bytes16_u32` | 13.00 | 13.00 | 13.00..14.41 |
| `pc_swap_nibbles_u32` | 15.00 | 15.00 | 13.59..15.44 |
| `pc_xorshift32` | 12.00 | 12.00 | 10.55..12.22 |

The representative input uses `0xA5C369F0` (32-bit values), `0xD3A57C9E102468BF` (64-bit values), mask `0x5555AAAA`, count 13, range 5..27, and width 37, with API-specific valid payloads. Boundary inputs use all-one values/masks, count 31, range 0..31, width 64, and zero where the API's boundary case calls for it. Special cases: `pc_bit_error_syndrome_u32` uses `0xA55A1234` plus its generated check bits; 64-bit CLZ/CTZ use zero at boundary; `pc_even_parity_insert_u32` uses payload `0x25C369F0` and `0x7FFFFFFF`; `pc_parity_strip_check_u32` uses an encoded valid word and zero.

## Isolated footprint from current link

The ESP-IDF linker map attributes **2,753 bytes `.flash.text`** and **0 bytes static RAM** (`.dram0.data` plus `.dram0.bss`) to the 37 production translation units when all public APIs are linked. This is object-attribution in this validation link and includes any code retained for those functions; another consumer link may differ. The audit suite object contributes 11,460 flash bytes and 12 static RAM bytes; `main.c` contributes 2,331 flash bytes and 40 static RAM bytes. The whole image is 211,904 bytes and includes ESP-IDF, startup/runtime, validation suite and benchmark harness, so it is not library size. The main task uses an 8,192-byte configured stack; one post-run high-water reading reported 6,508 bytes free (1,684 bytes observed use). That is one observed run, not a maximum stack bound.

The physical flash is 16 MB, while this ESP-IDF image header still reports 4 MB and boot logged that mismatch. It did not affect the run or app0 write, but the validation firmware does not advertise the full physical flash capacity in its image header.

## Historical ESP32-S3 measurements

These measurements were recorded during the earlier hardware validation. The production and audit-test sources have not changed since that run. The 2026-11-11 follow-up identified the same board but did not capture serial output, so these are historical results and were not freshly remeasured.

Measured on the designated COM37 ESP32-S3, revision 0.2, USB Serial/JTAG, 240 MHz CPU, 40 MHz crystal. Firmware used ESP-IDF 5.5.1, Xtensa GCC 14.2.0, production source compiled as C99, and `-O2`. Each API timing is a paired actual/no-op batch difference, median across 21 samples of 1,000 calls each. A volatile function-pointer table and volatile result sink prevent the compiler from removing calls. The median no-op batch was 15,002 cycles for 1,000 calls. Values below are cycles/call; ranges are observed min..max across the 21 paired samples.

| API | Representative input | Median cycles | Min..max |
|---|---|---:|---:|
| `pc_bit_byte_reverse_u32` | `A5C369F0` | 599.97 | 590.13..601.15 |
| `pc_bit_deinterleave4_u32` | `A5C369F0` | 740.05 | 730.13..744.60 |
| `pc_bit_error_syndrome_u32` | data `A55A1234`, SECDED checks | 6,670.05 | 6,660.13..6,684.49 |
| `pc_bit_extract_u64` | `D3A57C9E102468BF`, bits 9..47 | 780.05 | 770.13..784.23 |
| `pc_bit_gather_u32` | value `A5C369F0`, mask `5555AAAA` | 2,033.05 | 2,030.13..2,054.52 |
| `pc_bit_interleave4_u32` | lanes `A5C369F0` | 730.05 | 720.13..734.60 |
| `pc_bit_nibble_reverse_u32` | `A5C369F0` | 393.03 | 390.13..413.81 |
| `pc_bit_pair_reverse_u32` | `A5C369F0` | 284.56 | 280.13..290.57 |
| `pc_bit_reverse_u64` | `D3A57C9E102468BF` | 770.05 | 760.13..785.88 |
| `pc_bit_scatter_u32` | value `A5C369F0`, mask `5555AAAA` | 2,200.05 | 2,190.13..2,213.80 |
| `pc_bit_shuffle_even_odd_u32` | `A5C369F0` | 563.05 | 560.13..570.54 |
| `pc_bit_swap_u32` | `A5C369F0`, positions 3 and 29 | 505.65 | 500.13..524.17 |
| `pc_bit_unshuffle_even_odd_u32` | `A5C369F0` | 570.13 | 556.37..580.05 |
| `pc_bitset_count_ones_u32` | `A5C369F0` | 413.04 | 410.13..434.52 |
| `pc_bitset_rotate_left_u32` | `A5C369F0`, count 13 | 231.65 | 230.13..240.50 |
| `pc_clz_u64` | `D3A57C9E102468BF` | 510.05 | 500.13..523.78 |
| `pc_ctz_u64` | `D3A57C9E102468BF` | 530.55 | 526.33..542.72 |
| `pc_deinterleave_nibbles_u32` | `A5C369F0` | 473.06 | 470.13..480.05 |
| `pc_even_parity_insert_u32` | payload `25C369F0` | 420.05 | 410.13..424.22 |
| `pc_gray_decode_u64` | `7FFFFFFFFFFFFFFF` | 470.13 | 466.29..480.46 |
| `pc_gray_encode_u64` | `D3A57C9E102468BF` | 263.05 | 260.03..270.05 |
| `pc_interleave_bytes_u32` | `A5C369F0` | 310.13 | 296.41..320.05 |
| `pc_interleave_nibbles_u32` | `A5C369F0` | 473.03 | 470.13..480.05 |
| `pc_mask_between_u32` | bits 5..27 | 480.05 | 470.13..484.59 |
| `pc_mask_count_runs_u32` | `A5C369F0` | 442.93 | 440.13..464.51 |
| `pc_mask_is_contiguous_u32` | mask `0007F800` | 293.04 | 290.13..300.47 |
| `pc_mask_low_u64` | width 37 | 500.05 | 490.13..504.56 |
| `pc_mask_lowest_n_u32` | width 23 | 360.13 | 360.13..383.80 |
| `pc_parity_strip_check_u32` | even-parity word from payload `25C369F0` | 443.00 | 440.13..450.05 |
| `pc_parity_u64` | `D3A57C9E102468BF` | 480.05 | 470.13..483.87 |
| `pc_popcount_u64` | `D3A57C9E102468BF` | 640.13 | 636.29..650.05 |
| `pc_rotate_left_u64` | `D3A57C9E102468BF`, count 29 | 582.52 | 580.13..604.17 |
| `pc_secded_parity_u32` | data `A55A1234` | 3,920.05 | 3,910.13..3,934.52 |
| `pc_swap_bitpairs_u32` | `A5C369F0` | 290.13 | 286.30..300.05 |
| `pc_swap_bytes16_u32` | `A5C369F0` | 270.13 | 270.13..280.52 |
| `pc_swap_nibbles_u32` | `A5C369F0` | 300.05 | 290.13..309.44 |
| `pc_xorshift32` | state `12345678` | 263.06 | 260.13..283.80 |

These values characterize this board, compiler, optimization, link and harness only. In particular, gather/scatter are mask-population dependent, and other functions may vary with input.

The available report records representative-input results. Boundary-input cycle measurements are **NOT MEASURED** in the retained evidence.

## Isolated footprint and stack observation

The ESP-IDF linker map attributed 2,749 bytes of `.flash.text` to the 37 Binavex translation units when every API was referenced. It attributed 0 bytes of static `.dram0.data` and `.dram0.bss` to the library.

| Translation unit | Flash bytes | Static RAM bytes |
|---|---:|---:|
| `pc_bit_byte_reverse_u32.c` | 129 | 0 |
| `pc_bit_deinterleave4_u32.c` | 167 | 0 |
| `pc_bit_error_syndrome_u32.c` | 102 | 0 |
| `pc_bit_extract_u64.c` | 134 | 0 |
| `pc_bit_gather_u32.c` | 44 | 0 |
| `pc_bit_interleave4_u32.c` | 152 | 0 |
| `pc_bit_nibble_reverse_u32.c` | 49 | 0 |
| `pc_bit_pair_reverse_u32.c` | 33 | 0 |
| `pc_bit_reverse_u64.c` | 173 | 0 |
| `pc_bit_scatter_u32.c` | 45 | 0 |
| `pc_bit_shuffle_even_odd_u32.c` | 105 | 0 |
| `pc_bit_swap_u32.c` | 76 | 0 |
| `pc_bit_unshuffle_even_odd_u32.c` | 101 | 0 |
| `pc_bitset_count_ones_u32.c` | 55 | 0 |
| `pc_bitset_rotate_left_u32.c` | 11 | 0 |
| `pc_clz_u64.c` | 98 | 0 |
| `pc_ctz_u64.c` | 106 | 0 |
| `pc_deinterleave_nibbles_u32.c` | 87 | 0 |
| `pc_even_parity_insert_u32.c` | 56 | 0 |
| `pc_gray_decode_u64.c` | 83 | 0 |
| `pc_gray_encode_u64.c` | 20 | 0 |
| `pc_interleave_bytes_u32.c` | 35 | 0 |
| `pc_interleave_nibbles_u32.c` | 83 | 0 |
| `pc_mask_between_u32.c` | 68 | 0 |
| `pc_mask_count_runs_u32.c` | 63 | 0 |
| `pc_mask_is_contiguous_u32.c` | 28 | 0 |
| `pc_mask_low_u64.c` | 68 | 0 |
| `pc_mask_lowest_n_u32.c` | 40 | 0 |
| `pc_parity_strip_check_u32.c` | 58 | 0 |
| `pc_parity_u64.c` | 80 | 0 |
| `pc_popcount_u64.c` | 111 | 0 |
| `pc_rotate_left_u64.c` | 103 | 0 |
| `pc_secded_parity_u32.c` | 85 | 0 |
| `pc_swap_bitpairs_u32.c` | 26 | 0 |
| `pc_swap_bytes16_u32.c` | 26 | 0 |
| `pc_swap_nibbles_u32.c` | 26 | 0 |
| `pc_xorshift32.c` | 23 | 0 |

The complete validation app binary was 202,912 bytes and includes ESP-IDF runtime, startup, test code and benchmark harness; it is not the Binavex footprint. The main task had a 3,584-byte stack; one post-run high-water reading showed 1,980 bytes minimum free and 1,604 bytes observed use. This is not a maximum stack bound. Per-function flash figures are per translation unit in this validation link and are not guarantees for other link settings.
