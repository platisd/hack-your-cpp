# CWE-122: Heap-based Buffer Overflow

`400 * 300` doesn't fit in `uint16_t`, the cells vector ends up too small.

## Things to try

- `cwe run 122 -p asan -- 200 150` with the map of your office
- `cwe run 122 -p asan` with the default 400x300 map
- `cwe run 122 --cc clang -p integer` catches the wraparound itself
- `cwe run 122 -p glibcxx-assertions`, then `-- 300 300`: which row is the first one it catches?
- `cwe run 122 -p warnings` stays silent, now change `const uint16_t cellCount = ...` to `const uint16_t cellCount{...}`
- `cwe run 122 -p ubsan -- 65535 65535` for the signed overflow in `columns * rows`
