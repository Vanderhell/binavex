#include "pc_mask_lowest_n_u32.h"
#include <stddef.h>

bool rm_mask_lowest_n_u32(uint8_t n, uint32_t *mask)
{
    if (mask == NULL || n > 32u) return false;
    *mask = n == 32u ? UINT32_MAX : ((UINT32_C(1) << n) - 1u);
    return true;
}
