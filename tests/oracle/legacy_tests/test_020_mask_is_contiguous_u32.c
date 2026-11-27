#include "pc_mask_is_contiguous_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(!pc_mask_is_contiguous_u32(0u));
 CHECK(pc_mask_is_contiguous_u32(1u));
 CHECK(pc_mask_is_contiguous_u32(0x0000f000u));
 CHECK(pc_mask_is_contiguous_u32(0x80000000u));
 CHECK(pc_mask_is_contiguous_u32(UINT32_MAX));
 CHECK(!pc_mask_is_contiguous_u32(0x0000a000u));
 CHECK(!pc_mask_is_contiguous_u32(0x80000001u));
 return 0;}
