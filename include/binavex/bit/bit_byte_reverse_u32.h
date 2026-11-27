#ifndef BINAVEX_BIT_BIT_BYTE_REVERSE_U32_H
#define BINAVEX_BIT_BIT_BYTE_REVERSE_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Reverse bit order inside each byte; byte positions stay in place. */
uint32_t binavex_bit_byte_reverse_u32(uint32_t value);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_BYTE_REVERSE_U32_H */
