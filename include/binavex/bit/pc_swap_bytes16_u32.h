#ifndef PC_PC_SWAP_BYTES16_U32_H
#define PC_PC_SWAP_BYTES16_U32_H
#include <stdint.h>

/* Exchange the two bytes in each of the 16-bit halves of a 32-bit word. */
uint32_t pc_swap_bytes16_u32(uint32_t value);

#endif
