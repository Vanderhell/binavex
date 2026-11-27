#ifndef BINAVEX_BIT_GRAY_DECODE_U64_H
#define BINAVEX_BIT_GRAY_DECODE_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Decode a reflected 64-bit Gray code to its binary value. */
uint64_t binavex_gray_decode_u64(uint64_t gray);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_GRAY_DECODE_U64_H */
