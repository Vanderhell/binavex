#include "pc_bitset_rotate_left_u32.h"

uint32_t pc_bitset_rotate_left_u32(uint32_t word, uint32_t count)
{
    const uint32_t shift = count & 31u;
    if (shift == 0u) {
        return word;
    }
    return (word << shift) | (word >> (32u - shift));
}
