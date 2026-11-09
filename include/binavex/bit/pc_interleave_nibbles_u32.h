#ifndef PC_PC_INTERLEAVE_NIBBLES_U32_H
#define PC_PC_INTERLEAVE_NIBBLES_U32_H
#include <stdint.h>

/* Interleave the four nibbles of the high and low halfwords alternately. */
uint32_t pc_interleave_nibbles_u32(uint32_t value);

#endif
