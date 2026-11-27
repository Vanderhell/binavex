#include <binavex/bit/swap_nibbles_u32.h>

uint32_t binavex_swap_nibbles_u32(uint32_t value)
{
    return ((value & UINT32_C(0x0F0F0F0F)) << 4) |
           ((value & UINT32_C(0xF0F0F0F0)) >> 4);
}
