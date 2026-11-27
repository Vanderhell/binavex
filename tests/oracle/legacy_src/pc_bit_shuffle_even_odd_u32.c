#include "pc_bit_shuffle_even_odd_u32.h"

static uint32_t compress_even_bits(uint32_t x)
{
    x &= UINT32_C(0x55555555);
    x = (x | (x >> 1)) & UINT32_C(0x33333333);
    x = (x | (x >> 2)) & UINT32_C(0x0f0f0f0f);
    x = (x | (x >> 4)) & UINT32_C(0x00ff00ff);
    x = (x | (x >> 8)) & UINT32_C(0x0000ffff);
    return x;
}

uint32_t pc_bit_shuffle_even_odd_u32(uint32_t value)
{
    return compress_even_bits(value) | (compress_even_bits(value >> 1) << 16);
}
