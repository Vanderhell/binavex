#ifndef PRIMITIVECORE_BIT_ERROR_SYNDROME_U32_H
#define PRIMITIVECORE_BIT_ERROR_SYNDROME_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Compute extended Hamming(39,32) syndrome: bits 0..5 encode the one-based
 * error position (zero means none); bit 6 is overall parity mismatch.
 * Check byte bit 7 is reserved. Failure leaves syndrome unchanged. */
bool rm_bit_error_syndrome_u32(uint32_t received_data, uint8_t received_check_bits,
                               uint8_t *syndrome);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_bit_error_syndrome_u32
#define pc_bit_error_syndrome_u32 rm_bit_error_syndrome_u32
#endif
#ifndef pc_bit_error_syndrome_u32
#define pc_bit_error_syndrome_u32 rm_bit_error_syndrome_u32
#endif
#ifndef PC_PRIMITIVECORE_BIT_ERROR_SYNDROME_U32_H
#define PC_PRIMITIVECORE_BIT_ERROR_SYNDROME_U32_H PRIMITIVECORE_BIT_ERROR_SYNDROME_U32_H
#endif

