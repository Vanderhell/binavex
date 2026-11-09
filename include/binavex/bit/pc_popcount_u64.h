#ifndef PRIMITIVECORE_PC_POPCOUNT_U64_H
#define PRIMITIVECORE_PC_POPCOUNT_U64_H

#include <stdint.h>

/* Return the number of set bits in value (0..64). */
unsigned pc_popcount_u64(uint64_t value);

#endif
