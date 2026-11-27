#include <binavex/bit/bit_deinterleave4_u32.h>
#include <binavex/bit/bit_interleave4_u32.h>
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    CHECK(binavex_bit_deinterleave4_u32(0u)==0u);
    CHECK(binavex_bit_deinterleave4_u32(UINT32_MAX)==UINT32_MAX);
    CHECK(binavex_bit_deinterleave4_u32(1u)==1u);
    CHECK(binavex_bit_deinterleave4_u32(2u)==0x100u);
    CHECK(binavex_bit_deinterleave4_u32(4u)==0x10000u);
    CHECK(binavex_bit_deinterleave4_u32(8u)==0x01000000u);
    CHECK(binavex_bit_deinterleave4_u32(0x84210000u)==0x80402010u);
    for(uint32_t x=0;x<65536u;++x)
      CHECK(binavex_bit_deinterleave4_u32(binavex_bit_interleave4_u32(x))==x);
    return 0;
}
