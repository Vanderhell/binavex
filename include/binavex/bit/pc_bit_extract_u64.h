#ifndef PRIMITIVECORE_PC_BIT_EXTRACT_U64_H
#define PRIMITIVECORE_PC_BIT_EXTRACT_U64_H

#include <stdbool.h>
#include <stdint.h>

/* Extract inclusive bit range [first_bit,last_bit], right-aligned in *field.
 * Reject invalid bounds or null output; failure leaves *field unchanged. */
bool pc_bit_extract_u64(uint64_t value, uint8_t first_bit, uint8_t last_bit,
                        uint64_t *field);

#endif
