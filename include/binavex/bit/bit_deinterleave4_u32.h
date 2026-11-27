#ifndef BINAVEX_BIT_BIT_DEINTERLEAVE4_U32_H
#define BINAVEX_BIT_BIT_DEINTERLEAVE4_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Reverse binavex_bit_interleave4_u32: packed bit 4*i+k becomes byte-lane k bit i. */
uint32_t binavex_bit_deinterleave4_u32(uint32_t packed);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_DEINTERLEAVE4_U32_H */
