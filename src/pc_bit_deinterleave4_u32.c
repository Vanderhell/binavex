#include "pc_bit_deinterleave4_u32.h"

static uint32_t gather4(uint32_t x)
{
    x &= UINT32_C(0x11111111);
    x = (x | (x >> 3)) & UINT32_C(0x03030303);
    x = (x | (x >> 6)) & UINT32_C(0x000f000f);
    x = (x | (x >> 12)) & UINT32_C(0x000000ff);
    return x;
}

uint32_t rm_bit_deinterleave4_u32(uint32_t packed)
{
    return gather4(packed) |
           (gather4(packed >> 1) << 8) |
           (gather4(packed >> 2) << 16) |
           (gather4(packed >> 3) << 24);
}
