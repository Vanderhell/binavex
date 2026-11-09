#ifndef PC_XORSHIFT32_H
#define PC_XORSHIFT32_H
#include <stdint.h>

/* Advance one xorshift32 (13,17,5) state. Zero is a fixed point; use a
 * nonzero seed for the full period of 2^32 - 1 states. */
uint32_t pc_xorshift32(uint32_t state);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_xorshift32
#define pc_xorshift32 pc_xorshift32
#endif
#ifndef pc_xorshift32
#define pc_xorshift32 pc_xorshift32
#endif
#ifndef PC_PC_XORSHIFT32_H
#define PC_PC_XORSHIFT32_H PC_XORSHIFT32_H
#endif

