#ifndef PC_PC_CLZ_U64_H
#define PC_PC_CLZ_U64_H

#include <stdint.h>

/* Count leading zero bits; clz(0) is defined as 64. */
unsigned pc_clz_u64(uint64_t value);

#endif
