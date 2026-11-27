#include <binavex/bit/gray_encode_u64.h>

uint64_t binavex_gray_encode_u64(uint64_t value)
{
    return value ^ (value >> 1);
}
