#ifndef BINAVEX_BIT_SWAP_NIBBLES_U32_H
#define BINAVEX_BIT_SWAP_NIBBLES_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Exchange the high and low nibble in each byte of a 32-bit word. */
uint32_t binavex_swap_nibbles_u32(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_SWAP_NIBBLES_U32_H */
