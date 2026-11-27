# Binavex audit register

## API inventory and preservation

The namespace-migrated library has 37 public callable C99 functions in 37
self-contained headers and 37 production translation units. Every public
function uses the `binavex_` prefix. The ESP-IDF validation application and all
active host tests were migrated with the API. The original headers, sources,
27 root C tests, and ESP-IDF validation program are preserved under
`tests/oracle/legacy_*`.

## Current revision results

| Check | Result |
|---|---|
| Direct API tests | PASS, 37/37 public functions called by enabled tests |
| MSVC 19.42.34444 Debug / Release | PASS, 28/28 CTest entries each |
| GCC 16.1.0 MinGW UCRT Debug / Release | PASS, 28/28 each |
| Clang 22.1.8 Windows GNU target Debug / Release | PASS, 28/28 each |
| GCC 13.3.0 ASan / UBSan, Ubuntu 24.04 under WSL | PASS, 28/28 each |
| Installed `find_package(Binavex)` C consumer | PASS |
| `add_subdirectory` C consumer | PASS |
| Direct-source strict C99 consumer | PASS |
| ESP32-S3 after namespace migration | HW NOT VERIFIED |
| GitHub Actions for this revision | NOT RUN; push was blocked by an unreachable configured HTTPS proxy |

Host checks use strict warnings and C99. All 37 headers are included by an
enabled C++ smoke test. The deterministic differential suite and specialized
unit programs are retained; randomized sampling is not a proof over all
32-bit or 64-bit inputs.

## Historical evidence and changes

The pre-migration API revision has recorded GCC, Clang, MSVC, sanitizer,
GitHub Actions, and ESP32-S3 results in `TESTING.md` and `PERFORMANCE.md`. The
hardware firmware printed `BINAVEX_ALL37_PASS`; its cycle, flash, RAM, and
stack observations are historical and apply to the pre-namespace source.

No production bit algorithm changed during productization. The first migration
mapped one API to a different header because its name appeared in that
header's comment. Strict MSVC compilation caught the missing declaration.
Header selection now requires an actual prototype, all generated public
headers were reconstructed from the preserved originals, and the migrated
headers compile in C and C++ translation units.

## Remaining limits

- Current namespace-migrated ESP32-S3 firmware has not been built or run.
- Current-revision per-API cycles and isolated flash/RAM/stack have not been
  measured.
- Current-revision remote GitHub Actions have not run because push was blocked.
- Exhaustive verification of the full data domains is infeasible; the tests
  use finite-domain enumeration, exhaustive representative SECDED error
  positions, deterministic differential sampling, and invariants.
