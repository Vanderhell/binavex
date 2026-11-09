#include "pc_bit_interleave4_u32.h"

static uint32_t spread4(uint32_t x)
{
    x &= UINT32_C(0xff);
    x = (x | (x << 12)) & UINT32_C(0x000f000f);
    x = (x | (x << 6)) & UINT32_C(0x03030303);
    x = (x | (x << 3)) & UINT32_C(0x11111111);
    return x;
}

uint32_t pc_bit_interleave4_u32(uint32_t lanes)
{
    return spread4(lanes) |
           (spread4(lanes >> 8) << 1) |
           (spread4(lanes >> 16) << 2) |
           (spread4(lanes >> 24) << 3);
}
