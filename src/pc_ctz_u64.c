#include "pc_ctz_u64.h"

uint32_t pc_ctz_u64(uint64_t value)
{
    uint32_t count = 0u;

    if (value == UINT64_C(0)) {
        return 64u;
    }
    if ((value & UINT64_C(0xFFFFFFFF)) == 0u) {
        count += 32u;
        value >>= 32;
    }
    if ((value & UINT64_C(0xFFFF)) == 0u) {
        count += 16u;
        value >>= 16;
    }
    if ((value & UINT64_C(0xFF)) == 0u) {
        count += 8u;
        value >>= 8;
    }
    if ((value & UINT64_C(0xF)) == 0u) {
        count += 4u;
        value >>= 4;
    }
    if ((value & UINT64_C(0x3)) == 0u) {
        count += 2u;
        value >>= 2;
    }
    if ((value & UINT64_C(0x1)) == 0u) {
        ++count;
    }
    return count;
}
