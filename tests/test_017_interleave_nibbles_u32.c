#include "pc_interleave_nibbles_u32.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t state = UINT32_C(0x2135B17E);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static uint32_t oracle(uint32_t x)
{
    uint32_t out = 0;
    unsigned i;
    for (i = 0; i < 4; ++i) {
        const uint32_t a = (x >> (16u + 4u * i)) & UINT32_C(0xF);
        const uint32_t b = (x >> (4u * i)) & UINT32_C(0xF);
        out |= a << (4u + 8u * i);
        out |= b << (8u * i);
    }
    return out;
}

int main(void)
{
    uint32_t i;
    for (i = 0; i < UINT32_C(65536); ++i)
        if (pc_interleave_nibbles_u32(i) != oracle(i)) return 1;
    for (i = 0; i < UINT32_C(1000000); ++i) {
        const uint32_t x = next_u32();
        if (pc_interleave_nibbles_u32(x) != oracle(x)) return 2;
    }
    puts("PASS 1,065,536 nibble-interleave cases");
    return 0;
}
