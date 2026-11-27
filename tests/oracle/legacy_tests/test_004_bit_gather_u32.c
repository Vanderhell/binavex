#include "pc_bit_gather_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    CHECK(pc_bit_gather_u32(UINT32_MAX,0u)==0u);
    CHECK(pc_bit_gather_u32(0u,UINT32_MAX)==0u);
    CHECK(pc_bit_gather_u32(UINT32_MAX,UINT32_MAX)==UINT32_MAX);
    CHECK(pc_bit_gather_u32(0xaaaaaaaaU,0x55555555U)==0u);
    CHECK(pc_bit_gather_u32(0xaaaaaaaaU,0xaaaaaaaaU)==0x0000ffffU);
    CHECK(pc_bit_gather_u32(0x80000000U,0x80000000U)==1u);
    CHECK(pc_bit_gather_u32(0x80000000U,1u)==0u);
    return 0;
}
