#include "pc_swap_bytes16_u32.h"

uint32_t pc_swap_bytes16_u32(uint32_t value)
{
    return ((value & UINT32_C(0x00FF00FF)) << 8) |
           ((value & UINT32_C(0xFF00FF00)) >> 8);
}
