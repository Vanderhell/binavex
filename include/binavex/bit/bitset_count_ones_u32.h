#ifndef BINAVEX_BIT_BITSET_COUNT_ONES_U32_H
#define BINAVEX_BIT_BITSET_COUNT_ONES_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Return the population count of all 32 bits in word, in the range [0, 32]. */
uint32_t binavex_bitset_count_ones_u32(uint32_t word);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BITSET_COUNT_ONES_U32_H */
