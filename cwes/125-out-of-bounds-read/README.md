# CWE-125: Out-of-bounds Read

`MotorController::onStatus` uses a fault code from the bus as an index.

## Things to try

- `cwe run 125 -p plain` reads past `kFaultNames` and logs whatever is there
- `cwe run 125 -p asan` and `cwe run 125 -p glibcxx-assertions`
- `cwe run 125 -p valgrind` stays silent, the memory after `kFaultNames` is still valid memory
- `cwe run 125 -p plain -- 100000` with a code far past the end
- `cwe fuzz 125`
- Add a `Fault::Overheating` value and build the fixed variant with `-p warnings --fixed`, `-Wswitch` warns
