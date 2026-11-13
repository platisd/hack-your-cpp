# CWE-562: Return of Stack Variable Address

`auto` copies the calibration, `offsets()` returns a span into the copy.

The driver calls `signFirmware()` after `offsets()`, it has a signing key on its stack.

## Things to try

- `cwe run 562 -p unprotected`, what does the app get instead of the offsets? Then with `--cc clang`
- `cwe run 562 -p asan`
- `cwe run 562 -p warnings`, then with `--cc clang`
- `cwe run 562 -p analyzer`
- Change the return type to `std::array<float, 6>&`, then `-p warnings`
