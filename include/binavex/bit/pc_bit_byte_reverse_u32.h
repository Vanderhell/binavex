#ifndef PRIMITIVECORE_BIT_BYTE_REVERSE_U32_H
#define PRIMITIVECORE_BIT_BYTE_REVERSE_U32_H
#include <stdint.h>
/* Reverse bit order inside each byte; byte positions stay in place. */
uint32_t rm_bit_byte_reverse_u32(uint32_t value);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_bit_byte_reverse_u32
#define pc_bit_byte_reverse_u32 rm_bit_byte_reverse_u32
#endif
#ifndef pc_bit_byte_reverse_u32
#define pc_bit_byte_reverse_u32 rm_bit_byte_reverse_u32
#endif
#ifndef PC_PRIMITIVECORE_BIT_BYTE_REVERSE_U32_H
#define PC_PRIMITIVECORE_BIT_BYTE_REVERSE_U32_H PRIMITIVECORE_BIT_BYTE_REVERSE_U32_H
#endif

