#ifndef PC_PC_BITSET_ROTATE_LEFT_U32_H
#define PC_PC_BITSET_ROTATE_LEFT_U32_H
#include <stdint.h>

/* Rotate all 32 bits left; any uint32 count is reduced modulo 32. */
uint32_t pc_bitset_rotate_left_u32(uint32_t word, uint32_t count);

#endif
