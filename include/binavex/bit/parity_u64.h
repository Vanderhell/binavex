#ifndef BINAVEX_BIT_PARITY_U64_H
#define BINAVEX_BIT_PARITY_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return 1 for an odd number of set bits and 0 for an even number. */
uint32_t binavex_parity_u64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_PARITY_U64_H */
