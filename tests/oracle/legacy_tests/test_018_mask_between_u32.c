#include "pc_mask_between_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){uint32_t m=77u;
 CHECK(pc_mask_between_u32(0u,0u,&m)&&m==1u);
 CHECK(pc_mask_between_u32(4u,7u,&m)&&m==0xf0u);
 CHECK(pc_mask_between_u32(0u,31u,&m)&&m==UINT32_MAX);
 CHECK(pc_mask_between_u32(31u,31u,&m)&&m==0x80000000u);
 m=77u;CHECK(!pc_mask_between_u32(8u,7u,&m)&&m==77u);
 CHECK(!pc_mask_between_u32(0u,32u,&m)&&m==77u);
 CHECK(!pc_mask_between_u32(0u,0u,0)&&m==77u);
 return 0;}
