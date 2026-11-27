#include "pc_bit_scatter_u32.h"

uint32_t pc_bit_scatter_u32(uint32_t value, uint32_t mask)
{
    uint32_t scattered = 0u;
    while (mask != 0u) {
        const uint32_t lowest = mask & (0u - mask);
        if ((value & 1u) != 0u) {
            scattered |= lowest;
        }
        value >>= 1;
        mask &= mask - 1u;
    }
    return scattered;
}
