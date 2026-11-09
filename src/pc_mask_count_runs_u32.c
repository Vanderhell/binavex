#include "pc_mask_count_runs_u32.h"

uint8_t rm_mask_count_runs_u32(uint32_t mask)
{
    uint32_t x = mask & ~(mask << 1);
    x = x - ((x >> 1) & UINT32_C(0x55555555));
    x = (x & UINT32_C(0x33333333)) + ((x >> 2) & UINT32_C(0x33333333));
    x = (x + (x >> 4)) & UINT32_C(0x0f0f0f0f);
    x += x >> 8;
    x += x >> 16;
    return (uint8_t)(x & UINT32_C(0x3f));
}
