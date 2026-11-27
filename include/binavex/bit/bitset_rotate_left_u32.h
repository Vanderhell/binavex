#ifndef BINAVEX_BIT_BITSET_ROTATE_LEFT_U32_H
#define BINAVEX_BIT_BITSET_ROTATE_LEFT_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Rotate all 32 bits left; any uint32 count is reduced modulo 32. */
uint32_t binavex_bitset_rotate_left_u32(uint32_t word, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BITSET_ROTATE_LEFT_U32_H */
