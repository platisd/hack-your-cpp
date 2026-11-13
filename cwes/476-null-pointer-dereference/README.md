# CWE-476: NULL Pointer Dereference

A frame with an ID nobody registered makes `operator[]` insert a `nullptr`.

## Things to try

- `cwe run 476 -p ubsan`, then with `--cc clang`
- `cwe run 476 -p ubsan -- 0x100` uses the registered ID
- `cwe tidy 476` stays silent
- `cwe fuzz 476`
- Use `mHandlers[frame.id]` in `fixed.hpp`, it won't compile
