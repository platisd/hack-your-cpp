# CWE-787: Out-of-bounds Write

`TelemetryBuffer::push` writes one sample past `mSamples`.

## Things to try

- `cwe run 787 -p asan` stays silent: the extra sample lands on `mHead`, inside the same object
- `cwe run 787 -p ubsan` reports it with GCC, but not with `--cc clang`
- Change `mSamples[mHead] = sample` to `mSamples[mHead].value = sample.value`, Clang's UBSan now reports it
- Change `Sample mSamples[64]` to `std::array<Sample, 64>` and run `-p hardened`
- `cwe tidy 787`
