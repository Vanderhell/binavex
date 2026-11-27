#include "pc_clz_u64.h"

unsigned pc_clz_u64(uint64_t value)
{
    unsigned count = 0u;
    if (value == 0u) return 64u;
    if ((value >> 32u) == 0u) { count += 32u; value <<= 32u; }
    if ((value >> 48u) == 0u) { count += 16u; value <<= 16u; }
    if ((value >> 56u) == 0u) { count += 8u; value <<= 8u; }
    if ((value >> 60u) == 0u) { count += 4u; value <<= 4u; }
    if ((value >> 62u) == 0u) { count += 2u; value <<= 2u; }
    if ((value >> 63u) == 0u) { count += 1u; }
    return count;
}
