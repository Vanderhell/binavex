#ifndef PC_PC_SWAP_BITPAIRS_U32_H
#define PC_PC_SWAP_BITPAIRS_U32_H
#include <stdint.h>

/* Exchange the two adjacent 2-bit fields within each nibble of a word. */
uint32_t pc_swap_bitpairs_u32(uint32_t value);

#endif
