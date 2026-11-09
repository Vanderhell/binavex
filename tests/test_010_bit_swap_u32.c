#include "pc_bit_swap_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){uint32_t out=77u;
 CHECK(pc_bit_swap_u32(1u,0u,1u,&out)&&out==2u);
 CHECK(pc_bit_swap_u32(3u,0u,1u,&out)&&out==3u);
 CHECK(pc_bit_swap_u32(0x80000001u,0u,31u,&out)&&out==0x80000001u);
 CHECK(pc_bit_swap_u32(0u,12u,12u,&out)&&out==0u);
 out=77u;CHECK(!pc_bit_swap_u32(1u,32u,0u,&out)&&out==77u);
 CHECK(!pc_bit_swap_u32(1u,0u,0u,0));
 return 0;}
