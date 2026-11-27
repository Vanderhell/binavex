#ifndef BINAVEX_BIT_INTERLEAVE_BYTES_U32_H
#define BINAVEX_BIT_INTERLEAVE_BYTES_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Interleave the two bytes of the high/low halfword streams alternately. */
uint32_t binavex_interleave_bytes_u32(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_INTERLEAVE_BYTES_U32_H */
