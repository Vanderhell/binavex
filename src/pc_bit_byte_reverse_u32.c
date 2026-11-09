#include "pc_bit_byte_reverse_u32.h"

uint32_t rm_bit_byte_reverse_u32(uint32_t value)
{
    return ((value & UINT32_C(0x01010101)) << 7) |
           ((value & UINT32_C(0x02020202)) << 5) |
           ((value & UINT32_C(0x04040404)) << 3) |
           ((value & UINT32_C(0x08080808)) << 1) |
           ((value & UINT32_C(0x10101010)) >> 1) |
           ((value & UINT32_C(0x20202020)) >> 3) |
           ((value & UINT32_C(0x40404040)) >> 5) |
           ((value & UINT32_C(0x80808080)) >> 7);
}
