#ifndef BINAVEX_BIT_EVEN_PARITY_INSERT_U32_H
#define BINAVEX_BIT_EVEN_PARITY_INSERT_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Insert even parity in bit 31 of a 31-bit payload. False for bit 31 set or
 * null output; failure leaves word unchanged. */
bool binavex_even_parity_insert_u32(uint32_t payload, uint32_t *word);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_EVEN_PARITY_INSERT_U32_H */
