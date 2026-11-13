# CWE-129: Improper Validation of Array Index

The cast silences `-Wsign-compare`, so a fault code of `-1` passes the check.

## Things to try

- `cwe run 129 -p asan` and `cwe run 129 -p asan -- -5`
- Add `uint32_t mTotal{};` before `mCountPerFault`, `-p asan` goes silent
- `cwe run 129 -p glibcxx-assertions`
- Remove the `static_cast<int>` and run `-p warnings` and `-p plain`
- `cwe tidy 129`, then replace `operator[]` with `.at()`
- `cwe fuzz 129`
