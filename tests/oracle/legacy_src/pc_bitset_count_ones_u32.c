#include "pc_bitset_count_ones_u32.h"

uint32_t pc_bitset_count_ones_u32(uint32_t word)
{
    word -= (word >> 1u) & UINT32_C(0x55555555);
    word = (word & UINT32_C(0x33333333)) +
           ((word >> 2u) & UINT32_C(0x33333333));
    word = (word + (word >> 4u)) & UINT32_C(0x0F0F0F0F);
    word += word >> 8u;
    word += word >> 16u;
    return word & UINT32_C(0x3F);
}
