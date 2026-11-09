#ifndef PRIMITIVECORE_PC_CTZ_U64_H
#define PRIMITIVECORE_PC_CTZ_U64_H

#include <stdint.h>

/* Count trailing zero bits; pc_ctz_u64(0) is defined as 64. */
uint32_t pc_ctz_u64(uint64_t value);

#endif
