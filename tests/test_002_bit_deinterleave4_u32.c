#include "pc_bit_deinterleave4_u32.h"
#include "pc_bit_interleave4_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    CHECK(pc_bit_deinterleave4_u32(0u)==0u);
    CHECK(pc_bit_deinterleave4_u32(UINT32_MAX)==UINT32_MAX);
    CHECK(pc_bit_deinterleave4_u32(1u)==1u);
    CHECK(pc_bit_deinterleave4_u32(2u)==0x100u);
    CHECK(pc_bit_deinterleave4_u32(4u)==0x10000u);
    CHECK(pc_bit_deinterleave4_u32(8u)==0x01000000u);
    CHECK(pc_bit_deinterleave4_u32(0x84210000u)==0x80402010u);
    for(uint32_t x=0;x<65536u;++x)
      CHECK(pc_bit_deinterleave4_u32(pc_bit_interleave4_u32(x))==x);
    return 0;
}
