#include "pc_bitset_rotate_left_u32.h"
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
static uint32_t next(uint32_t *s) { *s ^= *s << 13; *s ^= *s >> 17; *s ^= *s << 5; return *s; }
static uint32_t oracle(uint32_t word, uint32_t count)
{
    uint32_t result = 0u, shift = count % 32u;
    for (uint32_t i = 0; i < 32u; ++i)
        if (((word >> i) & 1u) != 0u) result |= UINT32_C(1) << ((i + shift) % 32u);
    return result;
}
int main(void)
{
    for (uint32_t word = 0; word < 65536u; ++word)
        for (uint32_t count = 0; count < 64u; ++count)
            CHECK(pc_bitset_rotate_left_u32(word, count) == oracle(word, count));
    const uint32_t edge_counts[] = {0u, 1u, 31u, 32u, 33u, 63u, 64u, UINT32_MAX};
    for (uint32_t i = 0; i < 8u; ++i) {
        CHECK(pc_bitset_rotate_left_u32(UINT32_C(0x80000001), edge_counts[i]) == oracle(UINT32_C(0x80000001), edge_counts[i]));
    }
    uint32_t state = UINT32_C(0x1696C0DE);
    for (uint32_t n = 0; n < 1000000u; ++n) {
        uint32_t word = next(&state), count = next(&state);
        CHECK(pc_bitset_rotate_left_u32(word, count) == oracle(word, count));
    }
    return 0;
}
