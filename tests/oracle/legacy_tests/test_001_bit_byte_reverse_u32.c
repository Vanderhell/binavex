#include "pc_bit_byte_reverse_u32.h"
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){
 CHECK(pc_bit_byte_reverse_u32(0u)==0u);
 CHECK(pc_bit_byte_reverse_u32(1u)==0x80u);
 CHECK(pc_bit_byte_reverse_u32(0x80000000u)==0x01000000u);
 CHECK(pc_bit_byte_reverse_u32(0x01234567u)==0x80c4a2e6u);
 CHECK(pc_bit_byte_reverse_u32(0xffffffffu)==0xffffffffu);
 CHECK(pc_bit_byte_reverse_u32(pc_bit_byte_reverse_u32(0x01234567u))==0x01234567u);
 return 0;}
