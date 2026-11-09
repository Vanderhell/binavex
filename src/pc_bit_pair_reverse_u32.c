#include "pc_bit_pair_reverse_u32.h"

uint32_t rm_bit_pair_reverse_u32(uint32_t value)
{
    return ((value & UINT32_C(0x55555555)) << 1) |
           ((value >> 1) & UINT32_C(0x55555555));
}
