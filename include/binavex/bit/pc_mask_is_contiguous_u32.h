#ifndef PRIMITIVECORE_MASK_IS_CONTIGUOUS_U32_H
#define PRIMITIVECORE_MASK_IS_CONTIGUOUS_U32_H
#include <stdbool.h>
#include <stdint.h>
/* True iff nonzero mask contains one contiguous run of set bits. */
bool rm_mask_is_contiguous_u32(uint32_t mask);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_mask_is_contiguous_u32
#define pc_mask_is_contiguous_u32 rm_mask_is_contiguous_u32
#endif
#ifndef pc_mask_is_contiguous_u32
#define pc_mask_is_contiguous_u32 rm_mask_is_contiguous_u32
#endif
#ifndef PC_PRIMITIVECORE_MASK_IS_CONTIGUOUS_U32_H
#define PC_PRIMITIVECORE_MASK_IS_CONTIGUOUS_U32_H PRIMITIVECORE_MASK_IS_CONTIGUOUS_U32_H
#endif

