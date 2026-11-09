#ifndef PRIMITIVECORE_PC_BITSET_COUNT_ONES_U32_H
#define PRIMITIVECORE_PC_BITSET_COUNT_ONES_U32_H
#include <stdint.h>

/* Return the population count of all 32 bits in word, in the range [0, 32]. */
uint32_t pc_bitset_count_ones_u32(uint32_t word);

#endif
