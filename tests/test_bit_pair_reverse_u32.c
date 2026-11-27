#include <binavex/bit/bit_pair_reverse_u32.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(binavex_bit_pair_reverse_u32(0u)==0u);
 CHECK(binavex_bit_pair_reverse_u32(1u)==2u);
 CHECK(binavex_bit_pair_reverse_u32(0x55555555u)==0xaaaaaaaau);
 CHECK(binavex_bit_pair_reverse_u32(0x80000000u)==0x40000000u);
 CHECK(binavex_bit_pair_reverse_u32(UINT32_MAX)==UINT32_MAX);
 CHECK(binavex_bit_pair_reverse_u32(binavex_bit_pair_reverse_u32(0x12345678u))==0x12345678u);
 return 0;}
