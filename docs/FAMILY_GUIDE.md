# Binavex family guide

## What this family solves

**Bit operations and binary coding.** Bit masks, permutations, Gray coding, parity, bitset operations and xorshift support.

This guide describes the complete public family as an independent embedded-C product. Each primitive remains separately linkable; select only the headers and source units required by the application.

## When to use this family

Use Binavex when the application needs the operations listed below and requires deterministic behavior, explicit caller-owned memory, and no mandatory operating-system services.

## Family at a glance

```mermaid
flowchart LR
    A[Application input] --> B[Validate representation and bounds]
    B --> C[Select one public primitive]
    C --> D[Check status or output contract]
    D --> E[Use result with documented units]
```

## Primitive map

| Public header | Symbol | Purpose and contract | Validation source |
|---|---|---|---|
| `include/binavex/bit/pc_bit_byte_reverse_u32.h` | `pc_bit_byte_reverse_u32` | Reverse bit order inside each byte; byte positions stay in place. | tests/test_001_bit_byte_reverse_u32.c |
| `include/binavex/bit/pc_bit_deinterleave4_u32.h` | `pc_bit_deinterleave4_u32` | Reverse pc_bit_interleave4_u32: packed bit 4*i+k becomes byte-lane k bit i. | tests/test_002_bit_deinterleave4_u32.c |
| `include/binavex/bit/pc_bit_error_syndrome_u32.h` | `pc_bit_error_syndrome_u32` | Compute extended Hamming(39,32) syndrome: bits 0..5 encode the one-based error position (zero means none); bit 6 is overall parity mismatch. Check byte bit 7 is reserved. Failure leaves syndrome unchanged. | tests/test_003_bit_error_syndrome_u32.c |
| `include/binavex/bit/pc_bit_extract_u64.h` | `pc_bit_extract_u64` | Extract inclusive bit range [first_bit,last_bit], right-aligned in *field. Reject invalid bounds or null output; failure leaves *field unchanged. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_bit_gather_u32.h` | `pc_bit_gather_u32` | Pack value bits selected by mask, from lowest selected input bit to bit zero. | tests/test_004_bit_gather_u32.c |
| `include/binavex/bit/pc_bit_interleave4_u32.h` | `pc_bit_interleave4_u32` | Interleave four byte lanes: input byte k bit i becomes output bit 4*i+k. | tests/test_002_bit_deinterleave4_u32.c |
| `include/binavex/bit/pc_bit_nibble_reverse_u32.h` | `pc_bit_nibble_reverse_u32` | Reverse bit order independently inside each 4-bit nibble. | tests/test_006_bit_nibble_reverse_u32.c |
| `include/binavex/bit/pc_bit_pair_reverse_u32.h` | `pc_bit_pair_reverse_u32` | Exchange adjacent bits (0 with 1, 2 with 3, through 30 with 31). | tests/test_007_bit_pair_reverse_u32.c |
| `include/binavex/bit/pc_bit_reverse_u64.h` | `pc_bit_reverse_u64` | Reverse the order of all 64 bits; bit 0 becomes bit 63. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_bit_scatter_u32.h` | `pc_bit_scatter_u32` | Deposit low value bits into mask positions in ascending bit order. | tests/test_008_bit_scatter_u32.c |
| `include/binavex/bit/pc_bit_shuffle_even_odd_u32.h` | `pc_bit_shuffle_even_odd_u32` | Gather even source bits to output low half and odd source bits to high half. | tests/test_009_bit_shuffle_even_odd_u32.c |
| `include/binavex/bit/pc_bit_swap_u32.h` | `pc_bit_swap_u32` | Exchange two bit positions, numbered from the least significant bit. | tests/test_010_bit_swap_u32.c |
| `include/binavex/bit/pc_bit_unshuffle_even_odd_u32.h` | `pc_bit_unshuffle_even_odd_u32` | Interleave low-half bits into even positions and high-half bits into odd. | tests/test_011_bit_unshuffle_even_odd_u32.c |
| `include/binavex/bit/pc_bitset_count_ones_u32.h` | `pc_bitset_count_ones_u32` | Return the population count of all 32 bits in word, in the range [0, 32]. | tests/test_012_bitset_count_ones_u32.c |
| `include/binavex/bit/pc_bitset_rotate_left_u32.h` | `pc_bitset_rotate_left_u32` | Rotate all 32 bits left; any uint32 count is reduced modulo 32. | tests/test_013_bitset_rotate_left_u32.c |
| `include/binavex/bit/pc_clz_u64.h` | `pc_clz_u64` | The public header contains the authoritative signature and input/output contract. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_ctz_u64.h` | `pc_ctz_u64` | The public header contains the authoritative signature and input/output contract. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_deinterleave_nibbles_u32.h` | `pc_deinterleave_nibbles_u32` | Recover the high/low halfword nibble streams from alternating nibble lanes. | tests/test_014_deinterleave_nibbles_u32.c |
| `include/binavex/bit/pc_even_parity_insert_u32.h` | `pc_even_parity_insert_u32` | Insert even parity in bit 31 of a 31-bit payload. False for bit 31 set or null output; failure leaves word unchanged. | tests/test_015_even_parity_insert_u32.c |
| `include/binavex/bit/pc_gray_decode_u64.h` | `pc_gray_decode_u64` | Decode a reflected 64-bit Gray code to its binary value. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_gray_encode_u64.h` | `pc_gray_encode_u64` | Encode binary value as reflected Gray code: value XOR (value >> 1). | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_interleave_bytes_u32.h` | `pc_interleave_bytes_u32` | Interleave the two bytes of the high/low halfword streams alternately. | tests/test_016_interleave_bytes_u32.c |
| `include/binavex/bit/pc_interleave_nibbles_u32.h` | `pc_interleave_nibbles_u32` | Interleave the four nibbles of the high and low halfwords alternately. | tests/test_014_deinterleave_nibbles_u32.c |
| `include/binavex/bit/pc_mask_between_u32.h` | `pc_mask_between_u32` | Set inclusive bit positions [first_bit,last_bit], numbered from LSB zero. | tests/test_018_mask_between_u32.c |
| `include/binavex/bit/pc_mask_count_runs_u32.h` | `pc_mask_count_runs_u32` | Count runs of set bits; a run begins at bit 0 or after a zero bit. | tests/test_019_mask_count_runs_u32.c |
| `include/binavex/bit/pc_mask_is_contiguous_u32.h` | `pc_mask_is_contiguous_u32` | True iff nonzero mask contains one contiguous run of set bits. | tests/test_020_mask_is_contiguous_u32.c |
| `include/binavex/bit/pc_mask_low_u64.h` | `pc_mask_low_u64` | Build a mask with the lowest n bits set; accepts widths 0 through 64. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_mask_lowest_n_u32.h` | `pc_mask_lowest_n_u32` | Build a mask with the lowest n bits set; accepts widths 0 through 32. | tests/test_021_mask_lowest_n_u32.c |
| `include/binavex/bit/pc_parity_strip_check_u32.h` | `pc_parity_strip_check_u32` | Validate even parity over a 32-bit word, then return bits 0..30 as payload. False on odd parity or null output; failure leaves payload unchanged. | tests/test_022_parity_strip_check_u32.c |
| `include/binavex/bit/pc_parity_u64.h` | `pc_parity_u64` | Return 1 for an odd number of set bits and 0 for an even number. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_popcount_u64.h` | `pc_popcount_u64` | Return the number of set bits in value (0..64). | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_rotate_left_u64.h` | `pc_rotate_left_u64` | Rotate all 64 bits left; count is reduced modulo 64. | No enabled test source was found by symbol search. |
| `include/binavex/bit/pc_secded_parity_u32.h` | `pc_secded_parity_u32` | Generate seven check bits for extended even-parity Hamming(39,32). Data bits map LSB-first to non-power-of-two positions 1..38. Result bits 0..5 are parity for positions 1,2,4,8,16,32; bit 6 is overall parity. | tests/test_003_bit_error_syndrome_u32.c |
| `include/binavex/bit/pc_swap_bitpairs_u32.h` | `pc_swap_bitpairs_u32` | Exchange the two adjacent 2-bit fields within each nibble of a word. | tests/test_023_swap_bitpairs_u32.c |
| `include/binavex/bit/pc_swap_bytes16_u32.h` | `pc_swap_bytes16_u32` | Exchange the two bytes in each of the 16-bit halves of a 32-bit word. | tests/test_024_swap_bytes16_u32.c |
| `include/binavex/bit/pc_swap_nibbles_u32.h` | `pc_swap_nibbles_u32` | Exchange the high and low nibble in each byte of a 32-bit word. | tests/test_025_swap_nibbles_u32.c |
| `include/binavex/bit/pc_xorshift32.h` | `pc_xorshift32` | Advance one xorshift32 (13,17,5) state. Zero is a fixed point; use a nonzero seed for the full period of 2^32 - 1 states. | tests/test_026_xorshift32.c |

## Selection guidance

- Choose the primitive whose width, representation, rounding, saturation, wrapping, and error contract match the application.
- Do not substitute a similarly named function without checking the public header.
- Allocate state and buffers in the caller; respect documented aliasing and output-preservation rules.
- Treat entries marked without a validation source as requiring additional product-level tests before release.

## Integration checklist

1. Include only the required public header.
2. Compile the matching source translation unit or use the product CMake target.
3. Check every boolean/status return before consuming an output.
4. Add application-specific boundary tests for units, widths, invalid inputs, and overflow behavior.
5. Run the documented host tests before target integration.

## Complexity and footprint

The product is split into independent translation units. Exact flash, RAM, stack, and cycle costs depend on the selected functions, compiler, optimization, and MCU; unmeasured values remain explicitly marked PENDING in the testing documentation.

## Validation boundary

The API reference links each public entry to its implementation and available validation source. Hardware status is reported only when reproducible target evidence exists.
