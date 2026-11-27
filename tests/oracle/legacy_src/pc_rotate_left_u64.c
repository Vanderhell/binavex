#include "pc_rotate_left_u64.h"

uint64_t pc_rotate_left_u64(uint64_t value, uint32_t count)
{
    const uint32_t shift = count & 63u;
    if (shift == 0u) {
        return value;
    }
    return (value << shift) | (value >> (64u - shift));
}
