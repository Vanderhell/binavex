# Binavex API reference

This reference inventories all 37 callable public APIs. Public headers define the authoritative signatures and contracts. `tests/test_audit_differential.c` directly checks every API in Debug and Release; function-specific tests remain enabled.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and direct validation source.

## include/binavex/bit/pc_bit_byte_reverse_u32.h

**Public symbol:** pc_bit_byte_reverse_u32

**Implementation unit:** src/pc_bit_byte_reverse_u32.c

**Purpose and contract:** Reverse bit order inside each byte; byte positions stay in place.

**Validation source:** tests/test_001_bit_byte_reverse_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_deinterleave4_u32.h

**Public symbol:** pc_bit_deinterleave4_u32

**Implementation unit:** src/pc_bit_deinterleave4_u32.c

**Purpose and contract:** Reverse pc_bit_interleave4_u32: packed bit 4*i+k becomes byte-lane k bit i.

**Validation source:** tests/test_002_bit_deinterleave4_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_error_syndrome_u32.h

**Public symbol:** pc_bit_error_syndrome_u32

**Implementation unit:** src/pc_bit_error_syndrome_u32.c

**Purpose and contract:** Compute extended Hamming(39,32) syndrome: bits 0..5 encode the one-based error position (zero means none); bit 6 is overall parity mismatch. Check byte bit 7 is reserved. Failure leaves syndrome unchanged.

**Validation source:** tests/test_003_bit_error_syndrome_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_extract_u64.h

**Public symbol:** pc_bit_extract_u64

**Implementation unit:** src/pc_bit_extract_u64.c

**Purpose and contract:** Extract inclusive bit range [first_bit,last_bit], right-aligned in *field. Reject invalid bounds or null output; failure leaves *field unchanged.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_gather_u32.h

**Public symbol:** pc_bit_gather_u32

**Implementation unit:** src/pc_bit_gather_u32.c

**Purpose and contract:** Pack value bits selected by mask, from lowest selected input bit to bit zero.

**Validation source:** tests/test_004_bit_gather_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_interleave4_u32.h

**Public symbol:** pc_bit_interleave4_u32

**Implementation unit:** src/pc_bit_interleave4_u32.c

**Purpose and contract:** Interleave four byte lanes: input byte k bit i becomes output bit 4*i+k.

**Validation source:** tests/test_002_bit_deinterleave4_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_nibble_reverse_u32.h

**Public symbol:** pc_bit_nibble_reverse_u32

**Implementation unit:** src/pc_bit_nibble_reverse_u32.c

**Purpose and contract:** Reverse bit order independently inside each 4-bit nibble.

**Validation source:** tests/test_006_bit_nibble_reverse_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_pair_reverse_u32.h

**Public symbol:** pc_bit_pair_reverse_u32

**Implementation unit:** src/pc_bit_pair_reverse_u32.c

**Purpose and contract:** Exchange adjacent bits (0 with 1, 2 with 3, through 30 with 31).

**Validation source:** tests/test_007_bit_pair_reverse_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_reverse_u64.h

**Public symbol:** pc_bit_reverse_u64

**Implementation unit:** src/pc_bit_reverse_u64.c

**Purpose and contract:** Reverse the order of all 64 bits; bit 0 becomes bit 63.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_scatter_u32.h

**Public symbol:** pc_bit_scatter_u32

**Implementation unit:** src/pc_bit_scatter_u32.c

**Purpose and contract:** Deposit low value bits into mask positions in ascending bit order.

**Validation source:** tests/test_008_bit_scatter_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_shuffle_even_odd_u32.h

**Public symbol:** pc_bit_shuffle_even_odd_u32

**Implementation unit:** src/pc_bit_shuffle_even_odd_u32.c

**Purpose and contract:** Gather even source bits to output low half and odd source bits to high half.

**Validation source:** tests/test_009_bit_shuffle_even_odd_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_swap_u32.h

**Public symbol:** pc_bit_swap_u32

**Implementation unit:** src/pc_bit_swap_u32.c

**Purpose and contract:** Exchange two bit positions, numbered from the least significant bit.

**Validation source:** tests/test_010_bit_swap_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bit_unshuffle_even_odd_u32.h

**Public symbol:** pc_bit_unshuffle_even_odd_u32

**Implementation unit:** src/pc_bit_unshuffle_even_odd_u32.c

**Purpose and contract:** Interleave low-half bits into even positions and high-half bits into odd.

**Validation source:** tests/test_011_bit_unshuffle_even_odd_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bitset_count_ones_u32.h

**Public symbol:** pc_bitset_count_ones_u32

**Implementation unit:** src/pc_bitset_count_ones_u32.c

**Purpose and contract:** Return the population count of all 32 bits in word, in the range [0, 32].

**Validation source:** tests/test_012_bitset_count_ones_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_bitset_rotate_left_u32.h

**Public symbol:** pc_bitset_rotate_left_u32

**Implementation unit:** src/pc_bitset_rotate_left_u32.c

**Purpose and contract:** Rotate all 32 bits left; any uint32 count is reduced modulo 32.

**Validation source:** tests/test_013_bitset_rotate_left_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_clz_u64.h

**Public symbol:** pc_clz_u64

**Implementation unit:** src/pc_clz_u64.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_ctz_u64.h

**Public symbol:** pc_ctz_u64

**Implementation unit:** src/pc_ctz_u64.c

**Purpose and contract:** The public header contains the authoritative signature and input/output contract.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_deinterleave_nibbles_u32.h

**Public symbol:** pc_deinterleave_nibbles_u32

**Implementation unit:** src/pc_deinterleave_nibbles_u32.c

**Purpose and contract:** Recover the high/low halfword nibble streams from alternating nibble lanes.

**Validation source:** tests/test_014_deinterleave_nibbles_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_even_parity_insert_u32.h

**Public symbol:** pc_even_parity_insert_u32

**Implementation unit:** src/pc_even_parity_insert_u32.c

**Purpose and contract:** Insert even parity in bit 31 of a 31-bit payload. False for bit 31 set or null output; failure leaves word unchanged.

**Validation source:** tests/test_015_even_parity_insert_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_gray_decode_u64.h

**Public symbol:** pc_gray_decode_u64

**Implementation unit:** src/pc_gray_decode_u64.c

**Purpose and contract:** Decode a reflected 64-bit Gray code to its binary value.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_gray_encode_u64.h

**Public symbol:** pc_gray_encode_u64

**Implementation unit:** src/pc_gray_encode_u64.c

**Purpose and contract:** Encode binary value as reflected Gray code: value XOR (value >> 1).

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_interleave_bytes_u32.h

**Public symbol:** pc_interleave_bytes_u32

**Implementation unit:** src/pc_interleave_bytes_u32.c

**Purpose and contract:** Interleave the two bytes of the high/low halfword streams alternately.

**Validation source:** tests/test_016_interleave_bytes_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_interleave_nibbles_u32.h

**Public symbol:** pc_interleave_nibbles_u32

**Implementation unit:** src/pc_interleave_nibbles_u32.c

**Purpose and contract:** Interleave the four nibbles of the high and low halfwords alternately.

**Validation source:** tests/test_014_deinterleave_nibbles_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_mask_between_u32.h

**Public symbol:** pc_mask_between_u32

**Implementation unit:** src/pc_mask_between_u32.c

**Purpose and contract:** Set inclusive bit positions [first_bit,last_bit], numbered from LSB zero.

**Validation source:** tests/test_018_mask_between_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_mask_count_runs_u32.h

**Public symbol:** pc_mask_count_runs_u32

**Implementation unit:** src/pc_mask_count_runs_u32.c

**Purpose and contract:** Count runs of set bits; a run begins at bit 0 or after a zero bit.

**Validation source:** tests/test_019_mask_count_runs_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_mask_is_contiguous_u32.h

**Public symbol:** pc_mask_is_contiguous_u32

**Implementation unit:** src/pc_mask_is_contiguous_u32.c

**Purpose and contract:** True iff nonzero mask contains one contiguous run of set bits.

**Validation source:** tests/test_020_mask_is_contiguous_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_mask_low_u64.h

**Public symbol:** pc_mask_low_u64

**Implementation unit:** src/pc_mask_low_u64.c

**Purpose and contract:** Build a mask with the lowest n bits set; accepts widths 0 through 64.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_mask_lowest_n_u32.h

**Public symbol:** pc_mask_lowest_n_u32

**Implementation unit:** src/pc_mask_lowest_n_u32.c

**Purpose and contract:** Build a mask with the lowest n bits set; accepts widths 0 through 32.

**Validation source:** tests/test_021_mask_lowest_n_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_parity_strip_check_u32.h

**Public symbol:** pc_parity_strip_check_u32

**Implementation unit:** src/pc_parity_strip_check_u32.c

**Purpose and contract:** Validate even parity over a 32-bit word, then return bits 0..30 as payload. False on odd parity or null output; failure leaves payload unchanged.

**Validation source:** tests/test_022_parity_strip_check_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_parity_u64.h

**Public symbol:** pc_parity_u64

**Implementation unit:** src/pc_parity_u64.c

**Purpose and contract:** Return 1 for an odd number of set bits and 0 for an even number.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_popcount_u64.h

**Public symbol:** pc_popcount_u64

**Implementation unit:** src/pc_popcount_u64.c

**Purpose and contract:** Return the number of set bits in value (0..64).

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_rotate_left_u64.h

**Public symbol:** pc_rotate_left_u64

**Implementation unit:** src/pc_rotate_left_u64.c

**Purpose and contract:** Rotate all 64 bits left; count is reduced modulo 64.

**Validation source:** `tests/test_audit_differential.c` (100,000 deterministic cases where applicable)

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_secded_parity_u32.h

**Public symbol:** pc_secded_parity_u32

**Implementation unit:** src/pc_secded_parity_u32.c

**Purpose and contract:** Generate seven check bits for extended even-parity Hamming(39,32). Data bits map LSB-first to non-power-of-two positions 1..38. Result bits 0..5 are parity for positions 1,2,4,8,16,32; bit 6 is overall parity.

**Validation source:** tests/test_003_bit_error_syndrome_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_swap_bitpairs_u32.h

**Public symbol:** pc_swap_bitpairs_u32

**Implementation unit:** src/pc_swap_bitpairs_u32.c

**Purpose and contract:** Exchange the two adjacent 2-bit fields within each nibble of a word.

**Validation source:** tests/test_023_swap_bitpairs_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_swap_bytes16_u32.h

**Public symbol:** pc_swap_bytes16_u32

**Implementation unit:** src/pc_swap_bytes16_u32.c

**Purpose and contract:** Exchange the two bytes in each of the 16-bit halves of a 32-bit word.

**Validation source:** tests/test_024_swap_bytes16_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_swap_nibbles_u32.h

**Public symbol:** pc_swap_nibbles_u32

**Implementation unit:** src/pc_swap_nibbles_u32.c

**Purpose and contract:** Exchange the high and low nibble in each byte of a 32-bit word.

**Validation source:** tests/test_025_swap_nibbles_u32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/binavex/bit/pc_xorshift32.h

**Public symbol:** pc_xorshift32

**Implementation unit:** src/pc_xorshift32.c

**Purpose and contract:** Advance one xorshift32 (13,17,5) state. Zero is a fixed point; use a nonzero seed for the full period of 2^32 - 1 states.

**Validation source:** tests/test_026_xorshift32.c; `tests/test_audit_differential.c`

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

