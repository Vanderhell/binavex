#ifndef PRIMITIVECORE_SECDED_PARITY_U32_H
#define PRIMITIVECORE_SECDED_PARITY_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Generate seven check bits for extended even-parity Hamming(39,32).
 * Data bits map LSB-first to non-power-of-two positions 1..38. Result bits
 * 0..5 are parity for positions 1,2,4,8,16,32; bit 6 is overall parity. */
bool rm_secded_parity_u32(uint32_t data, uint8_t *check_bits);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_secded_parity_u32
#define pc_secded_parity_u32 rm_secded_parity_u32
#endif
#ifndef pc_secded_parity_u32
#define pc_secded_parity_u32 rm_secded_parity_u32
#endif
#ifndef PC_PRIMITIVECORE_SECDED_PARITY_U32_H
#define PC_PRIMITIVECORE_SECDED_PARITY_U32_H PRIMITIVECORE_SECDED_PARITY_U32_H
#endif

