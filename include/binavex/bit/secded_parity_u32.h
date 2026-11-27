#ifndef BINAVEX_BIT_SECDED_PARITY_U32_H
#define BINAVEX_BIT_SECDED_PARITY_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Generate seven check bits for extended even-parity Hamming(39,32).
 * Data bits map LSB-first to non-power-of-two positions 1..38. Result bits
 * 0..5 are parity for positions 1,2,4,8,16,32; bit 6 is overall parity. */
bool binavex_secded_parity_u32(uint32_t data, uint8_t *check_bits);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_SECDED_PARITY_U32_H */
