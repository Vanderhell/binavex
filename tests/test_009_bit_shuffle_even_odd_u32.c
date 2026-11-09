#include "pc_bit_shuffle_even_odd_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(pc_bit_shuffle_even_odd_u32(0u)==0u);
 CHECK(pc_bit_shuffle_even_odd_u32(1u)==1u);
 CHECK(pc_bit_shuffle_even_odd_u32(2u)==0x00010000u);
 CHECK(pc_bit_shuffle_even_odd_u32(0x55555555u)==0x0000ffffu);
 CHECK(pc_bit_shuffle_even_odd_u32(0xaaaaaaaau)==0xffff0000u);
 CHECK(pc_bit_shuffle_even_odd_u32(UINT32_MAX)==UINT32_MAX);
 return 0;}
