#ifndef BINAVEX_BIT_SWAP_BITPAIRS_U32_H
#define BINAVEX_BIT_SWAP_BITPAIRS_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Exchange the two adjacent 2-bit fields within each nibble of a word. */
uint32_t binavex_swap_bitpairs_u32(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_SWAP_BITPAIRS_U32_H */
