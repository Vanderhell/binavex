#ifndef PRIMITIVECORE_XORSHIFT32_H
#define PRIMITIVECORE_XORSHIFT32_H
#include <stdint.h>

/* Advance one xorshift32 (13,17,5) state. Zero is a fixed point; use a
 * nonzero seed for the full period of 2^32 - 1 states. */
uint32_t rm_xorshift32(uint32_t state);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_xorshift32
#define pc_xorshift32 rm_xorshift32
#endif
#ifndef pc_xorshift32
#define pc_xorshift32 rm_xorshift32
#endif
#ifndef PC_PRIMITIVECORE_XORSHIFT32_H
#define PC_PRIMITIVECORE_XORSHIFT32_H PRIMITIVECORE_XORSHIFT32_H
#endif

