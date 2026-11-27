#ifndef BINAVEX_BIT_GRAY_ENCODE_U64_H
#define BINAVEX_BIT_GRAY_ENCODE_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Encode binary value as reflected Gray code: value XOR (value >> 1). */
uint64_t binavex_gray_encode_u64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_GRAY_ENCODE_U64_H */
