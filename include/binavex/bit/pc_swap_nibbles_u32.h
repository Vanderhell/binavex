#ifndef PRIMITIVECORE_PC_SWAP_NIBBLES_U32_H
#define PRIMITIVECORE_PC_SWAP_NIBBLES_U32_H
#include <stdint.h>

/* Exchange the high and low nibble in each byte of a 32-bit word. */
uint32_t pc_swap_nibbles_u32(uint32_t value);

#endif
