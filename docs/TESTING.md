# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Migrated unit tests | 26 source programs | Host C99 | PENDING build gate | `tests/` |
| Hardware validation | 0 | ESP32-S3 | HW NOT VERIFIED | No firmware run yet |
| Sanitizers | 0 | Host | NOT TESTED | Toolchain setup pending |

Reproduce the host gate with:

```sh
cmake -S . -B build -DBINAVEX_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

The family records report ESP32-S3 validation for the source candidates. This
standalone product does not inherit that result as a post-extraction hardware
claim.
