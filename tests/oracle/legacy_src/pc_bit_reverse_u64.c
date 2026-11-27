#include "pc_bit_reverse_u64.h"

uint64_t pc_bit_reverse_u64(uint64_t value)
{
    value = ((value >> 1) & UINT64_C(0x5555555555555555)) |
            ((value & UINT64_C(0x5555555555555555)) << 1);
    value = ((value >> 2) & UINT64_C(0x3333333333333333)) |
            ((value & UINT64_C(0x3333333333333333)) << 2);
    value = ((value >> 4) & UINT64_C(0x0F0F0F0F0F0F0F0F)) |
            ((value & UINT64_C(0x0F0F0F0F0F0F0F0F)) << 4);
    value = ((value >> 8) & UINT64_C(0x00FF00FF00FF00FF)) |
            ((value & UINT64_C(0x00FF00FF00FF00FF)) << 8);
    value = ((value >> 16) & UINT64_C(0x0000FFFF0000FFFF)) |
            ((value & UINT64_C(0x0000FFFF0000FFFF)) << 16);
    value = (value >> 32) | (value << 32);
    return value;
}
