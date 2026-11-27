#include <binavex/bit/mask_count_runs_u32.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(binavex_mask_count_runs_u32(0u)==0u);
 CHECK(binavex_mask_count_runs_u32(1u)==1u);
 CHECK(binavex_mask_count_runs_u32(0x0000f000u)==1u);
 CHECK(binavex_mask_count_runs_u32(0x0000a000u)==2u);
 CHECK(binavex_mask_count_runs_u32(0x55555555u)==16u);
 CHECK(binavex_mask_count_runs_u32(UINT32_MAX)==1u);
 return 0;}
