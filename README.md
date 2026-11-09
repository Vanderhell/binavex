# Binavex

Binavex is a portable C99 library of deterministic bit masks, bit movement,
Gray coding, parity, population-count and xorshift operations for embedded
binary protocols and compact data transforms.

## Scope

The package contains 36 independently buildable public functions. The `pc_`
symbols are part of the stable public API.
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

## Architecture and integration

Each bit operation is isolated in its own C99 source file for selective
linking. Include `include/`, link `binavex`, or compile only the required
source files. No heap, threads, OS services or mutable global state are used.

## API and configuration

The public API is documented by the headers under `include/binavex/bit`.
`BINAVEX_BUILD_TESTS` controls host tests. Inputs use fixed-width unsigned
types; bit ordering and invalid-input contracts are function-specific.

## Resource and performance status

Embedded flash, RAM, stack and cycle measurements are `PENDING`; no host value
is presented as an MCU measurement. Linker garbage collection can remove
unused translation units.

## Limitations, security and release status

Host coverage is 26/26 enabled tests. ESP32-S3 validation is not complete, so
the package is not a production-candidate release. The bit transforms do not
provide cryptographic security and must not be used as encryption.

## Name and origin

Binavex combines *binarium* (binary) with *nexus* (connection). It describes
small operations that connect bit representations, masks and coded fields.
Its technical scope is bit operations, coding and binary transforms.

## License

Apache License 2.0, copyright Vanderhell. See `LICENSE` and `NOTICE`.
