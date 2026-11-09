#ifndef PC_BIT_INTERLEAVE4_U32_H
#define PC_BIT_INTERLEAVE4_U32_H

#include <stdint.h>

/* Interleave four byte lanes: input byte k bit i becomes output bit 4*i+k. */
uint32_t pc_bit_interleave4_u32(uint32_t lanes);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_bit_interleave4_u32
#define pc_bit_interleave4_u32 pc_bit_interleave4_u32
#endif
#ifndef pc_bit_interleave4_u32
#define pc_bit_interleave4_u32 pc_bit_interleave4_u32
#endif
#ifndef PC_PC_BIT_INTERLEAVE4_U32_H
#define PC_PC_BIT_INTERLEAVE4_U32_H PC_BIT_INTERLEAVE4_U32_H
#endif

