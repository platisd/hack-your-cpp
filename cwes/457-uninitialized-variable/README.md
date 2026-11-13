# CWE-457: Use of Uninitialized Variable

An untrusted tool opens a session, `canFlash` is never set.

## Things to try

- `cwe run 457 -p unprotected`, may the untrusted tool `0x99` flash the ECU?
- `cwe run 457 -p unprotected -- 0x10` and `-- 0x30` with trusted tools
- `cwe run 457 --cc clang -p msan` and `cwe run 457 -p valgrind`
- `cwe run 457 --cc clang -p ubsan`, it only reports `canFlash` if its byte happens to be neither 0 nor 1
- `cwe run 457 -p warnings` with `-O 0` and `-O 2`
- `cwe run 457 -p unprotected --flag=-ftrivial-auto-var-init=zero`
- `cwe tidy 457`
