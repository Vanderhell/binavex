#include "pc_even_parity_insert_u32.h"
#include <stddef.h>

bool rm_even_parity_insert_u32(uint32_t payload, uint32_t *word)
{
    if (word == NULL || (payload & UINT32_C(0x80000000)) != 0u) {
        return false;
    }
    uint32_t parity = payload;
    parity ^= parity >> 16u;
    parity ^= parity >> 8u;
    parity ^= parity >> 4u;
    parity ^= parity >> 2u;
    parity ^= parity >> 1u;
    *word = payload | ((parity & 1u) << 31u);
    return true;
}
