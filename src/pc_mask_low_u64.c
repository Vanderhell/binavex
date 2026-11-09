#include "pc_mask_low_u64.h"

#include <stddef.h>

bool pc_mask_low_u64(uint8_t n, uint64_t *mask)
{
    if (mask == NULL || n > 64u) {
        return false;
    }
    *mask = n == 64u ? UINT64_MAX : ((UINT64_C(1) << n) - 1u);
    return true;
}
