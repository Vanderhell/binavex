#include "pc_swap_bytes16_u32.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t state = UINT32_C(0x2122B17E);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static uint32_t oracle(uint32_t x)
{
    const uint32_t b0 = x & UINT32_C(0xFF);
    const uint32_t b1 = (x >> 8) & UINT32_C(0xFF);
    const uint32_t b2 = (x >> 16) & UINT32_C(0xFF);
    const uint32_t b3 = (x >> 24) & UINT32_C(0xFF);
    return (b2 << 24) | (b3 << 16) | (b0 << 8) | b1;
}

int main(void)
{
    uint32_t i;
    for (i = 0; i < UINT32_C(65536); ++i) {
        const uint32_t x = (i << 16) | (i ^ UINT32_C(0xFFFF));
        const uint32_t y = pc_swap_bytes16_u32(x);
        if (y != oracle(x) || pc_swap_bytes16_u32(y) != x) return 1;
    }
    for (i = 0; i < UINT32_C(1000000); ++i) {
        const uint32_t x = next_u32();
        if (pc_swap_bytes16_u32(x) != oracle(x)) return 2;
    }
    puts("PASS 1,065,536 swap-bytes16 differential/involution cases");
    return 0;
}
