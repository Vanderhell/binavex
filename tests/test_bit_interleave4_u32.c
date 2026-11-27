#include <binavex/bit/bit_interleave4_u32.h>
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    CHECK(binavex_bit_interleave4_u32(0u)==0u);
    CHECK(binavex_bit_interleave4_u32(UINT32_MAX)==UINT32_MAX);
    CHECK(binavex_bit_interleave4_u32(1u)==1u);
    CHECK(binavex_bit_interleave4_u32(0x100u)==2u);
    CHECK(binavex_bit_interleave4_u32(0x10000u)==4u);
    CHECK(binavex_bit_interleave4_u32(0x01000000u)==8u);
    CHECK(binavex_bit_interleave4_u32(0x80402010u)==0x84210000u);
    return 0;
}
