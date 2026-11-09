#ifndef PRIMITIVECORE_BIT_SWAP_U32_H
#define PRIMITIVECORE_BIT_SWAP_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Exchange two bit positions, numbered from the least significant bit. */
bool rm_bit_swap_u32(uint32_t value, uint8_t bit_a, uint8_t bit_b,
                     uint32_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_bit_swap_u32
#define pc_bit_swap_u32 rm_bit_swap_u32
#endif
#ifndef pc_bit_swap_u32
#define pc_bit_swap_u32 rm_bit_swap_u32
#endif
#ifndef PC_PRIMITIVECORE_BIT_SWAP_U32_H
#define PC_PRIMITIVECORE_BIT_SWAP_U32_H PRIMITIVECORE_BIT_SWAP_U32_H
#endif

