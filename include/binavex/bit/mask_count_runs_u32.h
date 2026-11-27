#ifndef BINAVEX_BIT_MASK_COUNT_RUNS_U32_H
#define BINAVEX_BIT_MASK_COUNT_RUNS_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Count runs of set bits; a run begins at bit 0 or after a zero bit. */
uint8_t binavex_mask_count_runs_u32(uint32_t mask);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_MASK_COUNT_RUNS_U32_H */
