#ifndef BINAVEX_BIT_MASK_LOW_U64_H
#define BINAVEX_BIT_MASK_LOW_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Build a mask with the lowest n bits set; accepts widths 0 through 64. */
bool binavex_mask_low_u64(uint8_t n, uint64_t *mask);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_MASK_LOW_U64_H */
