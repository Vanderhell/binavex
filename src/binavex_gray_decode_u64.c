#include <binavex/bit/gray_decode_u64.h>

uint64_t binavex_gray_decode_u64(uint64_t gray)
{
    gray ^= gray >> 1;
    gray ^= gray >> 2;
    gray ^= gray >> 4;
    gray ^= gray >> 8;
    gray ^= gray >> 16;
    gray ^= gray >> 32;
    return gray;
}
