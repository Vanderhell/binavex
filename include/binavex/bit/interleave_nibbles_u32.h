#ifndef BINAVEX_BIT_INTERLEAVE_NIBBLES_U32_H
#define BINAVEX_BIT_INTERLEAVE_NIBBLES_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Interleave the four nibbles of the high and low halfwords alternately. */
uint32_t binavex_interleave_nibbles_u32(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_INTERLEAVE_NIBBLES_U32_H */
