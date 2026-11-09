#include "pc_swap_bitpairs_u32.h"

uint32_t pc_swap_bitpairs_u32(uint32_t value)
{
    return ((value & UINT32_C(0x33333333)) << 2) |
           ((value & UINT32_C(0xCCCCCCCC)) >> 2);
}
