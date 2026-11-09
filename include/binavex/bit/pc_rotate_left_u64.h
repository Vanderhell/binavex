#ifndef PRIMITIVECORE_PC_ROTATE_LEFT_U64_H
#define PRIMITIVECORE_PC_ROTATE_LEFT_U64_H

#include <stdint.h>

/* Rotate all 64 bits left; count is reduced modulo 64. */
uint64_t pc_rotate_left_u64(uint64_t value, uint32_t count);

#endif
