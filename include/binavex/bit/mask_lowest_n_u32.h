#ifndef BINAVEX_BIT_MASK_LOWEST_N_U32_H
#define BINAVEX_BIT_MASK_LOWEST_N_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Build a mask with the lowest n bits set; accepts widths 0 through 32. */
bool binavex_mask_lowest_n_u32(uint8_t n, uint32_t *mask);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_MASK_LOWEST_N_U32_H */
