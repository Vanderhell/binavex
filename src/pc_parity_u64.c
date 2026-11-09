#include "pc_parity_u64.h"

uint32_t pc_parity_u64(uint64_t value)
{
    value ^= value >> 32;
    value ^= value >> 16;
    value ^= value >> 8;
    value ^= value >> 4;
    value ^= value >> 2;
    value ^= value >> 1;
    return (uint32_t)(value & UINT64_C(1));
}
