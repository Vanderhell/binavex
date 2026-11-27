#include "pc_parity_strip_check_u32.h"
#include <stddef.h>

bool pc_parity_strip_check_u32(uint32_t word, uint32_t *payload)
{
    if (payload == NULL) {
        return false;
    }
    uint32_t parity = word;
    parity ^= parity >> 16u;
    parity ^= parity >> 8u;
    parity ^= parity >> 4u;
    parity ^= parity >> 2u;
    parity ^= parity >> 1u;
    if ((parity & 1u) != 0u) {
        return false;
    }
    *payload = word & UINT32_C(0x7FFFFFFF);
    return true;
}
