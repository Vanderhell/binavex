#include "pc_bit_nibble_reverse_u32.h"

uint32_t pc_bit_nibble_reverse_u32(uint32_t value)
{
    return ((value & UINT32_C(0x11111111)) << 3) |
           ((value & UINT32_C(0x22222222)) << 1) |
           ((value & UINT32_C(0x44444444)) >> 1) |
           ((value & UINT32_C(0x88888888)) >> 3);
}
