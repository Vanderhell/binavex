#ifndef BINAVEX_BIT_ROTATE_LEFT_U64_H
#define BINAVEX_BIT_ROTATE_LEFT_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Rotate all 64 bits left; count is reduced modulo 64. */
uint64_t binavex_rotate_left_u64(uint64_t value, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_ROTATE_LEFT_U64_H */
