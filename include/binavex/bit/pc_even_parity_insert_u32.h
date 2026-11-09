#ifndef PRIMITIVECORE_EVEN_PARITY_INSERT_U32_H
#define PRIMITIVECORE_EVEN_PARITY_INSERT_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Insert even parity in bit 31 of a 31-bit payload. False for bit 31 set or
 * null output; failure leaves word unchanged. */
bool rm_even_parity_insert_u32(uint32_t payload, uint32_t *word);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_even_parity_insert_u32
#define pc_even_parity_insert_u32 rm_even_parity_insert_u32
#endif
#ifndef pc_even_parity_insert_u32
#define pc_even_parity_insert_u32 rm_even_parity_insert_u32
#endif
#ifndef PC_PRIMITIVECORE_EVEN_PARITY_INSERT_U32_H
#define PC_PRIMITIVECORE_EVEN_PARITY_INSERT_U32_H PRIMITIVECORE_EVEN_PARITY_INSERT_U32_H
#endif

