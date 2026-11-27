#ifndef BINAVEX_BIT_BIT_SCATTER_U32_H
#define BINAVEX_BIT_BIT_SCATTER_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Deposit low value bits into mask positions in ascending bit order. */
uint32_t binavex_bit_scatter_u32(uint32_t value, uint32_t mask);



#ifdef __cplusplus
}
#endif

#endif /* BINAVEX_BIT_BIT_SCATTER_U32_H */
