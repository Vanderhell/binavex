#include "pc_parity_strip_check_u32.h"
#include "pc_even_parity_insert_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(v) do { if (!(v)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
static unsigned parity(uint32_t v){unsigned p=0;while(v){p^=v&1u;v>>=1u;}return p;}
int main(void)
{
    uint32_t payload=0xA5A5A5A5u,word=0u;
    for(uint32_t w=0u;w<65536u;++w){payload=0xA5A5A5A5u;if(parity(w)==0u)CHECK(pc_parity_strip_check_u32(w,&payload)&&payload==(w&0x7fffffffu));else CHECK(!pc_parity_strip_check_u32(w,&payload)&&payload==0xA5A5A5A5u);}
    CHECK(pc_even_parity_insert_u32(UINT32_C(0x12345678),&word));
    CHECK(pc_parity_strip_check_u32(word,&payload)&&payload==UINT32_C(0x12345678));
    for(unsigned bit=0;bit<32u;++bit){payload=0xA5A5A5A5u;CHECK(!pc_parity_strip_check_u32(word^(UINT32_C(1)<<bit),&payload)&&payload==0xA5A5A5A5u);}
    CHECK(!pc_parity_strip_check_u32(0u,NULL));
    return 0;
}
