#ifndef BINAVEX_BIT_CLZ_U64_H
#define BINAVEX_BIT_CLZ_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Count leading zero bits; clz(0) is defined as 64. */
unsigned binavex_clz_u64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_CLZ_U64_H */
