# Binavex

Binavex is a portable C99 library of deterministic bit masks, bit movement,
Gray coding, parity, population-count and xorshift operations for embedded
binary protocols and compact data transforms.

## Scope

This first extraction contains 36 independently buildable public functions
from the PrimitiveCore bit family. The original `pc_` symbols are preserved.
No heap, operating-system service, thread or global mutable state is required.

## Build and test

```sh
cmake -S . -B build -DBINAVEX_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## Contracts

Operations use fixed-width integer inputs and return deterministic values. The
exact width, bit ordering and invalid-input behavior are specified in each
public header under `include/binavex/bit`.

## Validation status

Host extraction tests are migrated and must pass the independent CMake gate.
ESP32-S3 validation and isolated footprint measurements are pending for this
product; no hardware result is claimed yet.

## Name and origin

Binavex combines *binarium* (binary) with *nexus* (connection). It describes
small operations that connect bit representations, masks and coded fields.
The product originates from PrimitiveCore's
`bit/bit_operations_and_coding` family.

## License

Apache License 2.0, copyright Vanderhell. See `LICENSE` and `NOTICE`.
