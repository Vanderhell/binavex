#ifndef BINAVEX_BIT_DEINTERLEAVE_NIBBLES_U32_H
#define BINAVEX_BIT_DEINTERLEAVE_NIBBLES_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Recover the high/low halfword nibble streams from alternating nibble lanes. */
uint32_t binavex_deinterleave_nibbles_u32(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_DEINTERLEAVE_NIBBLES_U32_H */
