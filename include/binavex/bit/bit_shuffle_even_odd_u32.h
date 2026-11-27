#ifndef BINAVEX_BIT_BIT_SHUFFLE_EVEN_ODD_U32_H
#define BINAVEX_BIT_BIT_SHUFFLE_EVEN_ODD_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Gather even source bits to output low half and odd source bits to high half. */
uint32_t binavex_bit_shuffle_even_odd_u32(uint32_t value);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_SHUFFLE_EVEN_ODD_U32_H */
