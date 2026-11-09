#ifndef PC_PC_DEINTERLEAVE_NIBBLES_U32_H
#define PC_PC_DEINTERLEAVE_NIBBLES_U32_H
#include <stdint.h>

/* Recover the high/low halfword nibble streams from alternating nibble lanes. */
uint32_t pc_deinterleave_nibbles_u32(uint32_t value);

#endif
