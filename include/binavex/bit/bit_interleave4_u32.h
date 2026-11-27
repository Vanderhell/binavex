#ifndef BINAVEX_BIT_BIT_INTERLEAVE4_U32_H
#define BINAVEX_BIT_BIT_INTERLEAVE4_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Interleave four byte lanes: input byte k bit i becomes output bit 4*i+k. */
uint32_t binavex_bit_interleave4_u32(uint32_t lanes);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_INTERLEAVE4_U32_H */
