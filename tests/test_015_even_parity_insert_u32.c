#include "pc_even_parity_insert_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(v) do { if (!(v)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
static unsigned parity(uint32_t v){unsigned p=0;while(v){p^=v&1u;v>>=1u;}return p;}
int main(void)
{
    uint32_t word=0xA5A5A5A5u;
    CHECK(pc_even_parity_insert_u32(0u,&word)&&word==0u);
    CHECK(pc_even_parity_insert_u32(1u,&word)&&word==0x80000001u);
    CHECK(pc_even_parity_insert_u32(UINT32_C(0x7FFFFFFF),&word)&&word==UINT32_C(0xFFFFFFFF));
    for(uint32_t payload=0u;payload<65536u;++payload){CHECK(pc_even_parity_insert_u32(payload,&word));CHECK((word&UINT32_C(0x7FFFFFFF))==payload&&parity(word)==0u);}
    word=0xA5A5A5A5u;CHECK(!pc_even_parity_insert_u32(UINT32_C(0x80000000),&word)&&word==0xA5A5A5A5u);
    CHECK(!pc_even_parity_insert_u32(0u,NULL));
    return 0;
}
