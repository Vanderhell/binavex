#ifndef BINAVEX_BIT_PARITY_STRIP_CHECK_U32_H
#define BINAVEX_BIT_PARITY_STRIP_CHECK_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Validate even parity over a 32-bit word, then return bits 0..30 as payload.
 * False on odd parity or null output; failure leaves payload unchanged. */
bool binavex_parity_strip_check_u32(uint32_t word, uint32_t *payload);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_PARITY_STRIP_CHECK_U32_H */
