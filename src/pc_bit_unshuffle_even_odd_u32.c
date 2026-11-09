#include "pc_bit_unshuffle_even_odd_u32.h"

static uint32_t spread_even_bits(uint32_t x)
{
    x &= UINT32_C(0x0000ffff);
    x = (x | (x << 8)) & UINT32_C(0x00ff00ff);
    x = (x | (x << 4)) & UINT32_C(0x0f0f0f0f);
    x = (x | (x << 2)) & UINT32_C(0x33333333);
    x = (x | (x << 1)) & UINT32_C(0x55555555);
    return x;
}

uint32_t pc_bit_unshuffle_even_odd_u32(uint32_t value)
{
    uint32_t even = spread_even_bits(value);
    uint32_t odd = spread_even_bits(value >> 16);
    return even | (odd << 1);
}
