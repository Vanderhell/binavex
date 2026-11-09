#ifndef PRIMITIVECORE_MASK_COUNT_RUNS_U32_H
#define PRIMITIVECORE_MASK_COUNT_RUNS_U32_H
#include <stdint.h>
/* Count runs of set bits; a run begins at bit 0 or after a zero bit. */
uint8_t rm_mask_count_runs_u32(uint32_t mask);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_mask_count_runs_u32
#define pc_mask_count_runs_u32 rm_mask_count_runs_u32
#endif
#ifndef pc_mask_count_runs_u32
#define pc_mask_count_runs_u32 rm_mask_count_runs_u32
#endif
#ifndef PC_PRIMITIVECORE_MASK_COUNT_RUNS_U32_H
#define PC_PRIMITIVECORE_MASK_COUNT_RUNS_U32_H PRIMITIVECORE_MASK_COUNT_RUNS_U32_H
#endif

