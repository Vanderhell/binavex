#include "pc_swap_bitpairs_u32.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t state = UINT32_C(0x2124B17E);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static uint32_t oracle(uint32_t x)
{
    uint32_t result = 0;
    unsigned i;
    for (i = 0; i < 8; ++i) {
        const uint32_t nibble = (x >> (4u * i)) & UINT32_C(0xF);
        result |= (((nibble & UINT32_C(3)) << 2) | (nibble >> 2)) << (4u * i);
    }
    return result;
}

int main(void)
{
    uint32_t i;
    for (i = 0; i < UINT32_C(65536); ++i) {
        const uint32_t out = pc_swap_bitpairs_u32(i);
        if (out != oracle(i) || pc_swap_bitpairs_u32(out) != i) return 1;
    }
    for (i = 0; i < UINT32_C(1000000); ++i) {
        const uint32_t x = next_u32();
        if (pc_swap_bitpairs_u32(x) != oracle(x)) return 2;
    }
    puts("PASS 1,065,536 bitpair-swap differential/involution cases");
    return 0;
}
