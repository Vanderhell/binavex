#include "pc_mask_between_u32.h"
#include <stddef.h>

bool pc_mask_between_u32(uint8_t first_bit, uint8_t last_bit, uint32_t *mask)
{
    uint8_t width;
    uint32_t low_mask, result;
    if (mask == NULL || first_bit > last_bit || last_bit > 31u) return false;
    width = (uint8_t)(last_bit - first_bit + 1u);
    low_mask = width == 32u ? UINT32_MAX : ((UINT32_C(1) << width) - 1u);
    result = low_mask << first_bit;
    *mask = result;
    return true;
}
