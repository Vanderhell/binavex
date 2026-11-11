# Testing and validation

## Public API and direct coverage

The public inventory contains 37 callable functions across 37 headers. Each is directly called by the enabled `tests/test_audit_differential.c`; the 26 original unit programs remain enabled. The audit test uses explicit `CHECK` failures and remains active with `NDEBUG`.

The deterministic SplitMix64-seeded differential pass executes 100,000 input cases for full-width and bit-transform operations, comparing against independent bit-loop, positional, and counting reference models. Finite domains are covered systematically: all 0..64 and 0..32 low-mask widths; all valid inclusive ranges for 32-bit and 64-bit extraction/mask generation; byte inputs; 65,536 constructed four-lane interleave patterns; all 32 one-hot positions; and all 39 single-bit plus 741 double-bit SECDED error positions for a representative codeword. Gather/scatter, Gray, shuffle/unshuffle and nibble interleave/deinterleave round-trip properties are checked. This is broad deterministic evidence, not exhaustive enumeration of 32-/64-bit inputs.

The SECDED reference constructs parity from positional data placement and computes syndrome independently. Xorshift32 is checked against known vectors and a 100,000-state deterministic sequence using the specified `(13,17,5)` transition. Zero is a fixed point; xorshift is not cryptographically secure.

Invalid bounds, null pointers, reserved SECDED check bits and output preservation are directly tested. The test contains no `assert()` dependency.

## Host toolchain results

All configurations use C99 and strict warning settings (`-Wall -Wextra -Wpedantic -Werror` for GCC/Clang; `/W4 /WX` for MSVC).

| Toolchain | Configuration | Result |
|---|---|---|
| GCC 16.1.0 (WinLibs UCRT) | Debug | PASS, 27/27 CTest |
| GCC 16.1.0 (WinLibs UCRT) | Release | PASS, 27/27 CTest |
| ClangCL 19.1.5 | Debug | PASS, 27/27 CTest |
| ClangCL 19.1.5 | Release | PASS, 27/27 CTest |
| MSVC 19.42.34444 | Debug | PASS, 27/27 CTest |
| MSVC 19.42.34444 | Release | PASS, 27/27 CTest |
| Native Windows Clang driver | Debug/Release | NOT RUN: local standalone driver cannot link because MSVC runtime libraries are not on its search path; ClangCL above uses the installed Visual Studio toolchain |
| Local GCC ASan | — | NOT RUN: MinGW GCC cannot find `-lasan` |
| Local GCC UBSan | — | NOT RUN: MinGW GCC cannot find `-lubsan` |

GitHub Actions run `43026354650` on commit `eece181e4f72e9c6e6f2f200f0abf6837282b24a` completed successfully: 8/8 jobs passed (GCC Debug/Release, Clang Debug/Release, MSVC Debug/Release, ASan, UBSan). [Workflow run](https://github.com/Vanderhell/binavex/actions/runs/43026354650). CI executes native Linux GCC/Clang, MSVC Debug/Release, ASan and UBSan.

### Revalidation of current source

On 2026-11-11, the current source and tests (HEAD `3439e6f`; its difference from the CI-tested commit is documentation only) were rebuilt in clean temporary build directories with strict warnings:

| Toolchain | Configuration | Result |
|---|---|---|
| GCC 16.1.0 (WinLibs UCRT) | Debug | PASS, 27/27 CTest |
| GCC 16.1.0 (WinLibs UCRT) | Release | PASS, 27/27 CTest |
| MSVC 19.42.34444 | Debug | PASS, 27/27 CTest |
| MSVC 19.42.34444 | Release | PASS, 27/27 CTest |
| ClangCL 22.1.8 | Debug/Release | NOT RUN: this host lacks the Windows SDK and MSVC runtime libraries required by the linker |

The existing remote matrix supplies native Linux Clang and both sanitizer runtimes. Workflow run `43044147090` on commit `a11f6be2d06ba5f4fb7e2d2ed31d24addaf48495` completed successfully: 8/8 jobs passed (GCC Debug/Release, Clang Debug/Release, MSVC Debug/Release, ASan, UBSan). [Final workflow run](https://github.com/Vanderhell/binavex/actions/runs/43044147090).

## ESP32-S3 hardware

**Current hardware PASS: 37/37 public APIs.** On 2026-11-11, the designated ESP32-S3 on COM37 (USB Serial/JTAG, MAC `3c:0f:02:d9:77:30`, revision 0.2) ran the validation firmware built with ESP-IDF 5.5.1, Xtensa GCC 14.2.0, C99 production units, `-O3`, and confirmed 240 MHz CPU. The independent differential suite completed and printed `BINAVEX_ALL37_PASS|passed=37/37|first_failed_api=0`; no watchdog warning occurred during the final run. The suite exercises direct API calls, reference comparisons, boundaries and deterministic generated data. See `docs/PERFORMANCE.md` for per-API representative/boundary cycle medians and memory attribution.

The user designated this board for testing and authorized replacing its existing test firmware without a backup. Only app0 at offset `0x10000` was written, and esptool verified its digest after writing. NVS, bootloader, partition table, OTA metadata, app1, SPIFFS and coredump were not written. The binary was 211,904 bytes and fits the app0 partition. Physical flash is 16 MB; the image header still reports 4 MB, which ESP-IDF logged as a size mismatch. The test completed despite this warning. No hardware algorithm defect was found.

## Reproduce host tests

```sh
cmake -S . -B build -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release -DBINAVEX_BUILD_TESTS=ON -DBINAVEX_STRICT_WARNINGS=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

For Visual Studio multi-configuration builds:

```powershell
cmake -S . -B build -DBINAVEX_BUILD_TESTS=ON -DBINAVEX_STRICT_WARNINGS=ON
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

## Limits and test-only findings

No production defect was confirmed, so production algorithms were not changed. During test development, two incorrect expected values in the new test were corrected: the bit-swap vector had equal source bits, and the even-parity assertion compared a bit count to zero instead of checking its low bit. These were test-only errors and are fixed in the passing suite.

The full 32-bit input domains are not exhaustively enumerated. SECDED position errors are exhaustive for one representative codeword, while full-width data coverage is deterministic sampling. Single watermark readings are observations, not stack bounds. See `docs/PERFORMANCE.md` for current hardware measurements and configuration.
