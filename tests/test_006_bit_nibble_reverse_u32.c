#include "pc_bit_nibble_reverse_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(pc_bit_nibble_reverse_u32(0u)==0u);
 CHECK(pc_bit_nibble_reverse_u32(1u)==0x8u);
 CHECK(pc_bit_nibble_reverse_u32(0x12345678u)==0x84c2a6e1u);
 CHECK(pc_bit_nibble_reverse_u32(0xffffffffu)==0xffffffffu);
 CHECK(pc_bit_nibble_reverse_u32(pc_bit_nibble_reverse_u32(0x12345678u))==0x12345678u);
 return 0;}
