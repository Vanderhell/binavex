#ifndef BINAVEX_BIT_BIT_UNSHUFFLE_EVEN_ODD_U32_H
#define BINAVEX_BIT_BIT_UNSHUFFLE_EVEN_ODD_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Interleave low-half bits into even positions and high-half bits into odd. */
uint32_t binavex_bit_unshuffle_even_odd_u32(uint32_t value);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_UNSHUFFLE_EVEN_ODD_U32_H */
