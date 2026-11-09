#include "pc_interleave_nibbles_u32.h"

uint32_t pc_interleave_nibbles_u32(uint32_t value)
{
    return (value & UINT32_C(0xF0000000)) |
           ((value & UINT32_C(0x0000F000)) << 12) |
           ((value & UINT32_C(0x0F000000)) >> 4) |
           ((value & UINT32_C(0x00000F00)) << 8) |
           ((value & UINT32_C(0x00F00000)) >> 8) |
           ((value & UINT32_C(0x000000F0)) << 4) |
           ((value & UINT32_C(0x000F0000)) >> 12) |
           (value & UINT32_C(0x0000000F));
}
