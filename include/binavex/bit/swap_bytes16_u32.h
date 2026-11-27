#ifndef BINAVEX_BIT_SWAP_BYTES16_U32_H
#define BINAVEX_BIT_SWAP_BYTES16_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Exchange the two bytes in each of the 16-bit halves of a 32-bit word. */
uint32_t binavex_swap_bytes16_u32(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_SWAP_BYTES16_U32_H */
