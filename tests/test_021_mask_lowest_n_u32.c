#include "pc_mask_lowest_n_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){uint32_t m=99u;
 CHECK(pc_mask_lowest_n_u32(0u,&m)&&m==0u);
 CHECK(pc_mask_lowest_n_u32(1u,&m)&&m==1u);
 CHECK(pc_mask_lowest_n_u32(31u,&m)&&m==0x7fffffffu);
 CHECK(pc_mask_lowest_n_u32(32u,&m)&&m==UINT32_MAX);
 m=99u;CHECK(!pc_mask_lowest_n_u32(33u,&m)&&m==99u);
 CHECK(!pc_mask_lowest_n_u32(0u,0)&&m==99u);
 return 0;}
