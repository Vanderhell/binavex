#include "pc_interleave_bytes_u32.h"

uint32_t pc_interleave_bytes_u32(uint32_t value)
{
    return (value & UINT32_C(0xFF0000FF)) |
           ((value & UINT32_C(0x0000FF00)) << 8) |
           ((value & UINT32_C(0x00FF0000)) >> 8);
}
