# CWE-121: Stack-based Buffer Overflow

Four readings with 40 character names don't fit in 128 bytes.

## Things to try

- `cwe run 121 -p plain` looks fine, `cwe run 121 -p plain -- 10` really is fine
- `cwe run 121 -p fortify2` crashes without a report, `-p fortify3` reports it
- `cwe run 121 -p stack-protector` and `cwe run 121 -p glibcxx-assertions`
- `cwe run 121 -p hardened`, which check fires first?
- `cwe run 121 -p warnings`, the warning is about `used += written`, does it point to the bug?
- Replace `std::array<char, 128> line` with `char line[128]` and `line.size()` with `sizeof(line)`, then `-p glibcxx-assertions`
