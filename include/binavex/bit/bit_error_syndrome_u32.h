#ifndef BINAVEX_BIT_BIT_ERROR_SYNDROME_U32_H
#define BINAVEX_BIT_BIT_ERROR_SYNDROME_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Compute extended Hamming(39,32) syndrome: bits 0..5 encode the one-based
 * error position (zero means none); bit 6 is overall parity mismatch.
 * Check byte bit 7 is reserved. Failure leaves syndrome unchanged. */
bool binavex_bit_error_syndrome_u32(uint32_t received_data, uint8_t received_check_bits,
                               uint8_t *syndrome);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_ERROR_SYNDROME_U32_H */
