#include "pc_deinterleave_nibbles_u32.h"
#include "pc_interleave_nibbles_u32.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t state = UINT32_C(0x2136B17E);
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
        const uint32_t a = (x >> (4u * (2u * i + 1u))) & UINT32_C(0xF);
        const uint32_t b = (x >> (8u * i)) & UINT32_C(0xF);
        out |= a << (16u + 4u * i);
        out |= b << (4u * i);
    }
    return out;
}

int main(void)
{
    uint32_t i;
    for (i = 0; i < UINT32_C(65536); ++i) {
        uint32_t packed = 0;
        unsigned j;
        for (j = 0; j < 4; ++j)
            packed |= ((i >> (4u * j)) & UINT32_C(0xF)) << (8u * j);
        if (pc_deinterleave_nibbles_u32(packed) != oracle(packed) ||
            pc_deinterleave_nibbles_u32(packed) != i) return 1;
    }
    for (i = 0; i < UINT32_C(1000000); ++i) {
        const uint32_t x = next_u32();
        const uint32_t out = pc_deinterleave_nibbles_u32(x);
        if (out != oracle(x) || pc_interleave_nibbles_u32(out) != x ||
            pc_deinterleave_nibbles_u32(pc_interleave_nibbles_u32(x)) != x) return 2;
    }
    puts("PASS 1,065,536 deinterleave/oracle/round-trip cases");
    return 0;
}
