#ifndef PRIMITIVECORE_PC_MASK_LOW_U64_H
#define PRIMITIVECORE_PC_MASK_LOW_U64_H

#include <stdbool.h>
#include <stdint.h>

/* Build a mask with the lowest n bits set; accepts widths 0 through 64. */
bool pc_mask_low_u64(uint8_t n, uint64_t *mask);

#endif
