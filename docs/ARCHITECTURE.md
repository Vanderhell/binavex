# Architecture

Binavex is a stateless static C99 library. Each operation is stored in its own
source unit and the public headers expose the preserved `pc_` symbols. The
first extraction covers masks, bit permutations, parity, Gray code, bitset
helpers, 64-bit bit primitives and xorshift32.
