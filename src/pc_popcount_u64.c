#include "pc_popcount_u64.h"

unsigned pc_popcount_u64(uint64_t value)
{
    value -= (value >> 1u) & UINT64_C(0x5555555555555555);
    value = (value & UINT64_C(0x3333333333333333)) +
            ((value >> 2u) & UINT64_C(0x3333333333333333));
    value = (value + (value >> 4u)) & UINT64_C(0x0F0F0F0F0F0F0F0F);
    value *= UINT64_C(0x0101010101010101);
    return (unsigned)(value >> 56u);
}
