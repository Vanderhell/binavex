#include "pc_interleave_bytes_u32.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t state = UINT32_C(0x2137B17E);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static uint32_t oracle(uint32_t x)
{
    const uint32_t a1 = (x >> 24) & UINT32_C(0xFF);
    const uint32_t a0 = (x >> 16) & UINT32_C(0xFF);
    const uint32_t b1 = (x >> 8) & UINT32_C(0xFF);
    const uint32_t b0 = x & UINT32_C(0xFF);
    return (a1 << 24) | (b1 << 16) | (a0 << 8) | b0;
}

int main(void)
{
    uint32_t a, b;
    for (a = 0; a < 256; ++a)
        for (b = 0; b < 256; ++b) {
            const uint32_t x = (a << 16) | (b << 8);
            if (pc_interleave_bytes_u32(x) != oracle(x)) return 1;
        }
    for (a = 0; a < UINT32_C(1000000); ++a) {
        const uint32_t x = next_u32();
        if (pc_interleave_bytes_u32(x) != oracle(x)) return 2;
    }
    puts("PASS 1,065,536 byte-interleave cases");
    return 0;
}
