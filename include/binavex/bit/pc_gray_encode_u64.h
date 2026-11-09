#ifndef PRIMITIVECORE_PC_GRAY_ENCODE_U64_H
#define PRIMITIVECORE_PC_GRAY_ENCODE_U64_H

#include <stdint.h>

/* Encode binary value as reflected Gray code: value XOR (value >> 1). */
uint64_t pc_gray_encode_u64(uint64_t value);

#endif
