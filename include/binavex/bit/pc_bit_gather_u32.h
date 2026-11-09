#ifndef PC_BIT_GATHER_U32_H
#define PC_BIT_GATHER_U32_H

#include <stdint.h>

/* Pack value bits selected by mask, from lowest selected input bit to bit zero. */
uint32_t pc_bit_gather_u32(uint32_t value, uint32_t mask);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_bit_gather_u32
#define pc_bit_gather_u32 pc_bit_gather_u32
#endif
#ifndef pc_bit_gather_u32
#define pc_bit_gather_u32 pc_bit_gather_u32
#endif
#ifndef PC_PC_BIT_GATHER_U32_H
#define PC_PC_BIT_GATHER_U32_H PC_BIT_GATHER_U32_H
#endif

