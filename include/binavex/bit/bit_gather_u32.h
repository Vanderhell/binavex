#ifndef BINAVEX_BIT_BIT_GATHER_U32_H
#define BINAVEX_BIT_BIT_GATHER_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Pack value bits selected by mask, from lowest selected input bit to bit zero. */
uint32_t binavex_bit_gather_u32(uint32_t value, uint32_t mask);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_GATHER_U32_H */
