#ifndef PC_PC_PARITY_U64_H
#define PC_PC_PARITY_U64_H

#include <stdint.h>

/* Return 1 for an odd number of set bits and 0 for an even number. */
uint32_t pc_parity_u64(uint64_t value);

#endif
