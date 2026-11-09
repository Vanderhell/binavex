#ifndef PRIMITIVECORE_MASK_BETWEEN_U32_H
#define PRIMITIVECORE_MASK_BETWEEN_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Set inclusive bit positions [first_bit,last_bit], numbered from LSB zero. */
bool rm_mask_between_u32(uint8_t first_bit, uint8_t last_bit, uint32_t *mask);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_mask_between_u32
#define pc_mask_between_u32 rm_mask_between_u32
#endif
#ifndef pc_mask_between_u32
#define pc_mask_between_u32 rm_mask_between_u32
#endif
#ifndef PC_PRIMITIVECORE_MASK_BETWEEN_U32_H
#define PC_PRIMITIVECORE_MASK_BETWEEN_U32_H PRIMITIVECORE_MASK_BETWEEN_U32_H
#endif

