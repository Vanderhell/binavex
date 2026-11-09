#ifndef PRIMITIVECORE_PC_INTERLEAVE_BYTES_U32_H
#define PRIMITIVECORE_PC_INTERLEAVE_BYTES_U32_H
#include <stdint.h>

/* Interleave the two bytes of the high/low halfword streams alternately. */
uint32_t pc_interleave_bytes_u32(uint32_t value);

#endif
