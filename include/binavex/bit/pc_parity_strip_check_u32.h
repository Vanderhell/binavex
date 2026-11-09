#ifndef PC_PARITY_STRIP_CHECK_U32_H
#define PC_PARITY_STRIP_CHECK_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Validate even parity over a 32-bit word, then return bits 0..30 as payload.
 * False on odd parity or null output; failure leaves payload unchanged. */
bool pc_parity_strip_check_u32(uint32_t word, uint32_t *payload);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_parity_strip_check_u32
#define pc_parity_strip_check_u32 pc_parity_strip_check_u32
#endif
#ifndef pc_parity_strip_check_u32
#define pc_parity_strip_check_u32 pc_parity_strip_check_u32
#endif
#ifndef PC_PC_PARITY_STRIP_CHECK_U32_H
#define PC_PC_PARITY_STRIP_CHECK_U32_H PC_PARITY_STRIP_CHECK_U32_H
#endif

