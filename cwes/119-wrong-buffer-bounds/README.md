# CWE-119: Improper Restriction of Operations within the Bounds of a Memory Buffer

A malicious app sends 400 samples, `sizeof(samples)` lets them through.

## Things to try

- `cwe run 119 -p unprotected` crashes, but nothing tells you why
- `cwe run 119 --cc clang -p asan -O 1` misses it, `play` only reads `samples[0]` so the optimizer drops the overflowing stores
- Change `packet` in `main.cpp` to a `std::vector` sized at run time, then try `-O 1` again
- `cwe run 119 -p fortify2` and `cwe run 119 -p stack-protector`
- `cwe fuzz 119`
