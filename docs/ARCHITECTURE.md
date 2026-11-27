# Architecture

Binavex is a modular C99 library for bit masks and extraction, bit
permutations, interleaving, Gray coding, population counts, parity and
syndromes, rotations, and the xorshift32 state transition. Its 37 public
functions use the `binavex_` namespace and reside in self-contained headers
under `include/binavex/bit/`.

Each public function has a separate production translation unit. The
implementation uses caller-owned values and output pointers, with no required
heap allocation, operating-system service, threads, or third-party library.
The CMake target is `Binavex::Binavex`; selected source units can also be
compiled directly when an application needs only a subset.

Xorshift32 is a deterministic non-cryptographic state transformation and must
not be used as a cryptographic random generator.
