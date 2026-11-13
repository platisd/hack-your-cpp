# CWE-680: Integer Overflow to Buffer Overflow

`offset + chunk.size()` wraps around to `0` in `uint32_t` and passes the check.

The trigger takes the offset and the chunk size.

## Things to try

- `cwe run 680 -p asan -- 1024 256` is a normal chunk
- `cwe run 680 -p asan` with the default offset of `UINT32_MAX - 255`
- `cwe run 680 --cc clang -p integer`
- `cwe run 680 -p warnings`
- `cwe run 680 -p hardened`, does it help?
- `cwe fuzz 680`
