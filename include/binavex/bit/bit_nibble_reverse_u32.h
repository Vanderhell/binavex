#ifndef BINAVEX_BIT_BIT_NIBBLE_REVERSE_U32_H
#define BINAVEX_BIT_BIT_NIBBLE_REVERSE_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Reverse bit order independently inside each 4-bit nibble. */
uint32_t binavex_bit_nibble_reverse_u32(uint32_t value);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_NIBBLE_REVERSE_U32_H */
