#include <binavex/bit/xorshift32.h>
#include <stdint.h>
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"failed line %d\n",__LINE__); return 1; } } while (0)
int main(void)
{
    CHECK(binavex_xorshift32(0u)==0u);
    CHECK(binavex_xorshift32(1u)==UINT32_C(0x00042021));
    CHECK(binavex_xorshift32(UINT32_C(0x12345678))==UINT32_C(0x87985AA5));
    CHECK(binavex_xorshift32(UINT32_MAX)==UINT32_C(0x0003E01F));
    return 0;
}
