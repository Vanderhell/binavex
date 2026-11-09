#include "pc_bit_unshuffle_even_odd_u32.h"
#include "pc_bit_shuffle_even_odd_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(pc_bit_unshuffle_even_odd_u32(0u)==0u);
 CHECK(pc_bit_unshuffle_even_odd_u32(1u)==1u);
 CHECK(pc_bit_unshuffle_even_odd_u32(0x00010000u)==2u);
 CHECK(pc_bit_unshuffle_even_odd_u32(0x0000ffffu)==0x55555555u);
 CHECK(pc_bit_unshuffle_even_odd_u32(0xffff0000u)==0xaaaaaaaau);
 CHECK(pc_bit_unshuffle_even_odd_u32(pc_bit_shuffle_even_odd_u32(0x12345678u))==0x12345678u);
 return 0;}
