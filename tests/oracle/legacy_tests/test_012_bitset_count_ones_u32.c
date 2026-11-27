#include "pc_bitset_count_ones_u32.h"
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
static uint32_t next(uint32_t *s) { *s ^= *s << 13; *s ^= *s >> 17; *s ^= *s << 5; return *s; }
static uint32_t oracle(uint32_t x)
{
    uint32_t n = 0u;
    while (x != 0u) { n += x % 2u; x /= 2u; }
    return n;
}
int main(void)
{
    for (uint32_t x = 0; x < 65536u; ++x)
        CHECK(pc_bitset_count_ones_u32(x) == oracle(x));
    CHECK(pc_bitset_count_ones_u32(0u) == 0u);
    CHECK(pc_bitset_count_ones_u32(UINT32_MAX) == 32u);
    uint32_t state = UINT32_C(0x1689C0DE);
    for (uint32_t n = 0; n < 1000000u; ++n) {
        uint32_t x = next(&state);
        CHECK(pc_bitset_count_ones_u32(x) == oracle(x));
    }
    return 0;
}
