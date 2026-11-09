#include "pc_bit_scatter_u32.h"
#include "pc_bit_gather_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    CHECK(pc_bit_scatter_u32(UINT32_MAX,0u)==0u);
    CHECK(pc_bit_scatter_u32(0u,UINT32_MAX)==0u);
    CHECK(pc_bit_scatter_u32(UINT32_MAX,UINT32_MAX)==UINT32_MAX);
    CHECK(pc_bit_scatter_u32(1u,0x80000000u)==0x80000000u);
    CHECK(pc_bit_scatter_u32(0x80000000u,1u)==0u);
    CHECK(pc_bit_scatter_u32(UINT32_MAX,0x55555555U)==0x55555555U);
    for(uint32_t value=0;value<256u;++value)
      for(uint32_t mask=0;mask<256u;++mask) {
        uint32_t count=0u, copy=mask;
        while(copy!=0u){count+=copy&1u;copy>>=1;}
        CHECK(pc_bit_gather_u32(pc_bit_scatter_u32(value,mask),mask)==(value & ((1u << count)-1u)));
      }
    return 0;
}
