#include "pc_mask_is_contiguous_u32.h"

bool rm_mask_is_contiguous_u32(uint32_t mask)
{
    uint32_t lowest;
    if (mask == 0u) return false;
    lowest = mask & (UINT32_C(0) - mask);
    return (mask & (mask + lowest)) == 0u;
}
