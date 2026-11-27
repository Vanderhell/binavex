#ifndef BINAVEX_BIT_POPCOUNT_U64_H
#define BINAVEX_BIT_POPCOUNT_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return the number of set bits in value (0..64). */
unsigned binavex_popcount_u64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_POPCOUNT_U64_H */
