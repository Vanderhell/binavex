#ifndef BINAVEX_BIT_MASK_IS_CONTIGUOUS_U32_H
#define BINAVEX_BIT_MASK_IS_CONTIGUOUS_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* True iff nonzero mask contains one contiguous run of set bits. */
bool binavex_mask_is_contiguous_u32(uint32_t mask);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_MASK_IS_CONTIGUOUS_U32_H */
