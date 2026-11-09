#include "pc_bit_swap_u32.h"
#include <stddef.h>

bool pc_bit_swap_u32(uint32_t value, uint8_t bit_a, uint8_t bit_b,
                     uint32_t *result)
{
    uint32_t bits;
    if (result == NULL || bit_a > 31u || bit_b > 31u) return false;
    if (((value >> bit_a) & 1u) != ((value >> bit_b) & 1u)) {
        bits = (UINT32_C(1) << bit_a) | (UINT32_C(1) << bit_b);
        value ^= bits;
    }
    *result = value;
    return true;
}
