#include "pc_mask_count_runs_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(pc_mask_count_runs_u32(0u)==0u);
 CHECK(pc_mask_count_runs_u32(1u)==1u);
 CHECK(pc_mask_count_runs_u32(0x0000f000u)==1u);
 CHECK(pc_mask_count_runs_u32(0x0000a000u)==2u);
 CHECK(pc_mask_count_runs_u32(0x55555555u)==16u);
 CHECK(pc_mask_count_runs_u32(UINT32_MAX)==1u);
 return 0;}
