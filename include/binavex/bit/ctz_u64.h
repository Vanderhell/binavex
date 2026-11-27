#ifndef BINAVEX_BIT_CTZ_U64_H
#define BINAVEX_BIT_CTZ_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Count trailing zero bits; binavex_ctz_u64(0) is defined as 64. */
uint32_t binavex_ctz_u64(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_CTZ_U64_H */
