#ifndef BINAVEX_BIT_XORSHIFT32_H
#define BINAVEX_BIT_XORSHIFT32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Advance one xorshift32 (13,17,5) state. Zero is a fixed point; use a
 * nonzero seed for the full period of 2^32 - 1 states. */
uint32_t binavex_xorshift32(uint32_t state);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_XORSHIFT32_H */
