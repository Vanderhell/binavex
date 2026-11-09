#include "pc_bit_error_syndrome_u32.h"
#include "pc_secded_parity_u32.h"
#include <stdint.h>
#include <stdio.h>
#define CHECK(v) do { if (!(v)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
static void flip(uint32_t *data,uint8_t *checks,unsigned position){unsigned c=0,d=0;for(unsigned p=1;p<=38u;++p){if((p&(p-1u))==0u){if(p==position)*checks^=(uint8_t)(1u<<c);++c;}else{if(p==position)*data^=UINT32_C(1)<<d;++d;}}if(position==39u)*checks^=0x40u;}
int main(void)
{
    const uint32_t original=UINT32_C(0x12345678);uint8_t checks=0u,syndrome=0xA5u;
    CHECK(pc_secded_parity_u32(original,&checks));
    CHECK(pc_bit_error_syndrome_u32(original,checks,&syndrome)&&syndrome==0u);
    for(unsigned position=1u;position<=39u;++position){uint32_t data=original;uint8_t bits=checks;flip(&data,&bits,position);CHECK(pc_bit_error_syndrome_u32(data,bits,&syndrome));CHECK(syndrome==(position==39u?0x40u:(uint8_t)(position|0x40u)));}
    for(unsigned a=1u;a<=39u;++a)for(unsigned b=a+1u;b<=39u;++b){uint32_t data=original;uint8_t bits=checks;flip(&data,&bits,a);flip(&data,&bits,b);CHECK(pc_bit_error_syndrome_u32(data,bits,&syndrome));const unsigned position_syndrome=a==39u?b:(b==39u?a:(a^b));CHECK(syndrome==(uint8_t)position_syndrome);}
    syndrome=0xA5u;CHECK(!pc_bit_error_syndrome_u32(original,0x80u,&syndrome)&&syndrome==0xA5u);
    CHECK(!pc_bit_error_syndrome_u32(original,checks,NULL));
    return 0;
}
