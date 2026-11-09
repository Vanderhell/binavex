#ifndef PC_PC_BIT_REVERSE_U64_H
#define PC_PC_BIT_REVERSE_U64_H

#include <stdint.h>

/* Reverse the order of all 64 bits; bit 0 becomes bit 63. */
uint64_t pc_bit_reverse_u64(uint64_t value);

#endif
