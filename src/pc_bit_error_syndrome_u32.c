#include "pc_bit_error_syndrome_u32.h"
#include <stddef.h>

bool rm_bit_error_syndrome_u32(uint32_t received_data, uint8_t received_check_bits,
                               uint8_t *syndrome)
{
    if (syndrome == NULL || (received_check_bits & UINT8_C(0x80)) != 0u) {
        return false;
    }
    uint8_t result = 0u;
    uint8_t overall = 0u;
    unsigned data_bit = 0u;
    unsigned check_bit = 0u;
    for (unsigned position = 1u; position <= 38u; ++position) {
        uint8_t bit;
        if ((position & (position - 1u)) == 0u) {
            bit = (uint8_t)((received_check_bits >> check_bit) & 1u);
            ++check_bit;
        } else {
            bit = (uint8_t)((received_data >> data_bit) & 1u);
            ++data_bit;
        }
        if (bit != 0u) {
            result ^= (uint8_t)position;
            overall ^= 1u;
        }
    }
    overall ^= (uint8_t)((received_check_bits >> 6u) & 1u);
    *syndrome = (uint8_t)(result | (overall << 6u));
    return true;
}
