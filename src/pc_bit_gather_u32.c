#include "pc_bit_gather_u32.h"

uint32_t pc_bit_gather_u32(uint32_t value, uint32_t mask)
{
    uint32_t gathered = 0u;
    uint32_t output_bit = 1u;
    while (mask != 0u) {
        const uint32_t lowest = mask & (0u - mask);
        if ((value & lowest) != 0u) {
            gathered |= output_bit;
        }
        mask &= mask - 1u;
        output_bit <<= 1;
    }
    return gathered;
}
