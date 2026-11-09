# Binavex API reference

Complete public-header inventory generated from the current source tree. Headers remain authoritative.

## include/binavex/bit/pc_bit_byte_reverse_u32.h

Public API: pc_bit_byte_reverse_u32

Contract: Reverse bit order inside each byte; byte positions stay in place.

Header path: include/binavex/bit/pc_bit_byte_reverse_u32.h

## include/binavex/bit/pc_bit_deinterleave4_u32.h

Public API: pc_bit_deinterleave4_u32

Contract: Reverse pc_bit_interleave4_u32: packed bit 4*i+k becomes byte-lane k bit i.

Header path: include/binavex/bit/pc_bit_deinterleave4_u32.h

## include/binavex/bit/pc_bit_error_syndrome_u32.h

Public API: pc_bit_error_syndrome_u32

Contract: Compute extended Hamming(39,32) syndrome: bits 0..5 encode the one-based error position (zero means none); bit 6 is overall parity mismatch. Check byte bit 7 is reserved. Failure leaves syndrome unchanged.

Header path: include/binavex/bit/pc_bit_error_syndrome_u32.h

## include/binavex/bit/pc_bit_extract_u64.h

Public API: pc_bit_extract_u64

Contract: Extract inclusive bit range [first_bit,last_bit], right-aligned in *field. Reject invalid bounds or null output; failure leaves *field unchanged.

Header path: include/binavex/bit/pc_bit_extract_u64.h

## include/binavex/bit/pc_bit_gather_u32.h

Public API: pc_bit_gather_u32

Contract: Pack value bits selected by mask, from lowest selected input bit to bit zero.

Header path: include/binavex/bit/pc_bit_gather_u32.h

## include/binavex/bit/pc_bit_interleave4_u32.h

Public API: pc_bit_interleave4_u32

Contract: Interleave four byte lanes: input byte k bit i becomes output bit 4*i+k.

Header path: include/binavex/bit/pc_bit_interleave4_u32.h

## include/binavex/bit/pc_bit_nibble_reverse_u32.h

Public API: pc_bit_nibble_reverse_u32

Contract: Reverse bit order independently inside each 4-bit nibble.

Header path: include/binavex/bit/pc_bit_nibble_reverse_u32.h

## include/binavex/bit/pc_bit_pair_reverse_u32.h

Public API: pc_bit_pair_reverse_u32

Contract: Exchange adjacent bits (0 with 1, 2 with 3, through 30 with 31).

Header path: include/binavex/bit/pc_bit_pair_reverse_u32.h

## include/binavex/bit/pc_bit_reverse_u64.h

Public API: pc_bit_reverse_u64

Contract: Reverse the order of all 64 bits; bit 0 becomes bit 63.

Header path: include/binavex/bit/pc_bit_reverse_u64.h

## include/binavex/bit/pc_bit_scatter_u32.h

Public API: pc_bit_scatter_u32

Contract: Deposit low value bits into mask positions in ascending bit order.

Header path: include/binavex/bit/pc_bit_scatter_u32.h

## include/binavex/bit/pc_bit_shuffle_even_odd_u32.h

Public API: pc_bit_shuffle_even_odd_u32

Contract: Gather even source bits to output low half and odd source bits to high half.

Header path: include/binavex/bit/pc_bit_shuffle_even_odd_u32.h

## include/binavex/bit/pc_bit_swap_u32.h

Public API: pc_bit_swap_u32

Contract: Exchange two bit positions, numbered from the least significant bit.

Header path: include/binavex/bit/pc_bit_swap_u32.h

## include/binavex/bit/pc_bit_unshuffle_even_odd_u32.h

Public API: pc_bit_unshuffle_even_odd_u32

Contract: Interleave low-half bits into even positions and high-half bits into odd.

Header path: include/binavex/bit/pc_bit_unshuffle_even_odd_u32.h

## include/binavex/bit/pc_bitset_count_ones_u32.h

Public API: pc_bitset_count_ones_u32

Contract: Return the population count of all 32 bits in word, in the range [0, 32].

Header path: include/binavex/bit/pc_bitset_count_ones_u32.h

## include/binavex/bit/pc_bitset_rotate_left_u32.h

Public API: pc_bitset_rotate_left_u32

Contract: Rotate all 32 bits left; any uint32 count is reduced modulo 32.

Header path: include/binavex/bit/pc_bitset_rotate_left_u32.h

## include/binavex/bit/pc_clz_u64.h

Public API: pc_clz_u64

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/binavex/bit/pc_clz_u64.h

## include/binavex/bit/pc_ctz_u64.h

Public API: pc_ctz_u64

Contract: The public header contains the authoritative signature and input/output contract.

Header path: include/binavex/bit/pc_ctz_u64.h

## include/binavex/bit/pc_deinterleave_nibbles_u32.h

Public API: pc_deinterleave_nibbles_u32

Contract: Recover the high/low halfword nibble streams from alternating nibble lanes.

Header path: include/binavex/bit/pc_deinterleave_nibbles_u32.h

## include/binavex/bit/pc_even_parity_insert_u32.h

Public API: pc_even_parity_insert_u32

Contract: Insert even parity in bit 31 of a 31-bit payload. False for bit 31 set or null output; failure leaves word unchanged.

Header path: include/binavex/bit/pc_even_parity_insert_u32.h

## include/binavex/bit/pc_gray_decode_u64.h

Public API: pc_gray_decode_u64

Contract: Decode a reflected 64-bit Gray code to its binary value.

Header path: include/binavex/bit/pc_gray_decode_u64.h

## include/binavex/bit/pc_gray_encode_u64.h

Public API: pc_gray_encode_u64

Contract: Encode binary value as reflected Gray code: value XOR (value >> 1).

Header path: include/binavex/bit/pc_gray_encode_u64.h

## include/binavex/bit/pc_interleave_bytes_u32.h

Public API: pc_interleave_bytes_u32

Contract: Interleave the two bytes of the high/low halfword streams alternately.

Header path: include/binavex/bit/pc_interleave_bytes_u32.h

## include/binavex/bit/pc_interleave_nibbles_u32.h

Public API: pc_interleave_nibbles_u32

Contract: Interleave the four nibbles of the high and low halfwords alternately.

Header path: include/binavex/bit/pc_interleave_nibbles_u32.h

## include/binavex/bit/pc_mask_between_u32.h

Public API: pc_mask_between_u32

Contract: Set inclusive bit positions [first_bit,last_bit], numbered from LSB zero.

Header path: include/binavex/bit/pc_mask_between_u32.h

## include/binavex/bit/pc_mask_count_runs_u32.h

Public API: pc_mask_count_runs_u32

Contract: Count runs of set bits; a run begins at bit 0 or after a zero bit.

Header path: include/binavex/bit/pc_mask_count_runs_u32.h

## include/binavex/bit/pc_mask_is_contiguous_u32.h

Public API: pc_mask_is_contiguous_u32

Contract: True iff nonzero mask contains one contiguous run of set bits.

Header path: include/binavex/bit/pc_mask_is_contiguous_u32.h

## include/binavex/bit/pc_mask_low_u64.h

Public API: pc_mask_low_u64

Contract: Build a mask with the lowest n bits set; accepts widths 0 through 64.

Header path: include/binavex/bit/pc_mask_low_u64.h

## include/binavex/bit/pc_mask_lowest_n_u32.h

Public API: pc_mask_lowest_n_u32

Contract: Build a mask with the lowest n bits set; accepts widths 0 through 32.

Header path: include/binavex/bit/pc_mask_lowest_n_u32.h

## include/binavex/bit/pc_parity_strip_check_u32.h

Public API: pc_parity_strip_check_u32

Contract: Validate even parity over a 32-bit word, then return bits 0..30 as payload. False on odd parity or null output; failure leaves payload unchanged.

Header path: include/binavex/bit/pc_parity_strip_check_u32.h

## include/binavex/bit/pc_parity_u64.h

Public API: pc_parity_u64

Contract: Return 1 for an odd number of set bits and 0 for an even number.

Header path: include/binavex/bit/pc_parity_u64.h

## include/binavex/bit/pc_popcount_u64.h

Public API: pc_popcount_u64

Contract: Return the number of set bits in value (0..64).

Header path: include/binavex/bit/pc_popcount_u64.h

## include/binavex/bit/pc_rotate_left_u64.h

Public API: pc_rotate_left_u64

Contract: Rotate all 64 bits left; count is reduced modulo 64.

Header path: include/binavex/bit/pc_rotate_left_u64.h

## include/binavex/bit/pc_secded_parity_u32.h

Public API: pc_secded_parity_u32

Contract: Generate seven check bits for extended even-parity Hamming(39,32). Data bits map LSB-first to non-power-of-two positions 1..38. Result bits 0..5 are parity for positions 1,2,4,8,16,32; bit 6 is overall parity.

Header path: include/binavex/bit/pc_secded_parity_u32.h

## include/binavex/bit/pc_swap_bitpairs_u32.h

Public API: pc_swap_bitpairs_u32

Contract: Exchange the two adjacent 2-bit fields within each nibble of a word.

Header path: include/binavex/bit/pc_swap_bitpairs_u32.h

## include/binavex/bit/pc_swap_bytes16_u32.h

Public API: pc_swap_bytes16_u32

Contract: Exchange the two bytes in each of the 16-bit halves of a 32-bit word.

Header path: include/binavex/bit/pc_swap_bytes16_u32.h

## include/binavex/bit/pc_swap_nibbles_u32.h

Public API: pc_swap_nibbles_u32

Contract: Exchange the high and low nibble in each byte of a 32-bit word.

Header path: include/binavex/bit/pc_swap_nibbles_u32.h

## include/binavex/bit/pc_xorshift32.h

Public API: pc_xorshift32

Contract: Advance one xorshift32 (13,17,5) state. Zero is a fixed point; use a nonzero seed for the full period of 2^32 - 1 states.

Header path: include/binavex/bit/pc_xorshift32.h
