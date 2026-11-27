#ifndef BINAVEX_BIT_MASK_BETWEEN_U32_H
#define BINAVEX_BIT_MASK_BETWEEN_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Set inclusive bit positions [first_bit,last_bit], numbered from LSB zero. */
bool binavex_mask_between_u32(uint8_t first_bit, uint8_t last_bit, uint32_t *mask);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_MASK_BETWEEN_U32_H */
