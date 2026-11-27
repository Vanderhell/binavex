#ifndef BINAVEX_BIT_BIT_SWAP_U32_H
#define BINAVEX_BIT_BIT_SWAP_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exchange two bit positions, numbered from the least significant bit. */
bool binavex_bit_swap_u32(uint32_t value, uint8_t bit_a, uint8_t bit_b,
                     uint32_t *result);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_SWAP_U32_H */
