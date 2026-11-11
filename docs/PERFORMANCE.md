# Performance and memory

## Previously recorded ESP32-S3 measurements

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
