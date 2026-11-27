#ifndef BINAVEX_BIT_BIT_REVERSE_U64_H
#define BINAVEX_BIT_BIT_REVERSE_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Reverse the order of all 64 bits; bit 0 becomes bit 63. */
uint64_t binavex_bit_reverse_u64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_REVERSE_U64_H */
