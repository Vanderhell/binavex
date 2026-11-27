#ifndef BINAVEX_BIT_BIT_PAIR_REVERSE_U32_H
#define BINAVEX_BIT_BIT_PAIR_REVERSE_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exchange adjacent bits (0 with 1, 2 with 3, through 30 with 31). */
uint32_t binavex_bit_pair_reverse_u32(uint32_t value);


#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_PAIR_REVERSE_U32_H */
