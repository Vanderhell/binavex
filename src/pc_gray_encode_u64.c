#include "pc_gray_encode_u64.h"

uint64_t pc_gray_encode_u64(uint64_t value)
{
    return value ^ (value >> 1);
}
