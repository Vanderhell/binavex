#include "pc_xorshift32.h"

uint32_t pc_xorshift32(uint32_t state)
{
    state ^= state << 13u;
    state ^= state >> 17u;
    state ^= state << 5u;
    return state;
}
