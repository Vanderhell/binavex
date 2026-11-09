#ifndef PC_BIT_DEINTERLEAVE4_U32_H
#define PC_BIT_DEINTERLEAVE4_U32_H

#include <stdint.h>

/* Reverse pc_bit_interleave4_u32: packed bit 4*i+k becomes byte-lane k bit i. */
uint32_t pc_bit_deinterleave4_u32(uint32_t packed);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_bit_deinterleave4_u32
#define pc_bit_deinterleave4_u32 pc_bit_deinterleave4_u32
#endif
#ifndef pc_bit_deinterleave4_u32
#define pc_bit_deinterleave4_u32 pc_bit_deinterleave4_u32
#endif
#ifndef pc_bit_interleave4_u32
#define pc_bit_interleave4_u32 pc_bit_interleave4_u32
#endif
#ifndef PC_PC_BIT_DEINTERLEAVE4_U32_H
#define PC_PC_BIT_DEINTERLEAVE4_U32_H PC_BIT_DEINTERLEAVE4_U32_H
#endif

