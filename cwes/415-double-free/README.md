# CWE-415: Double Free

The broker rejects payloads over 256 bytes, `mqtt_publish` frees the message and so does `MqttMsg`.

## Things to try

- `cwe run 415 -p asan -- 100` is accepted, `cwe run 415 -p asan` is rejected
- `cwe run 415 -p unprotected`, glibc notices, but only because nothing reused the memory in between
- `cwe run 415 -p valgrind`
- `cwe tidy 415` and `cwe tidy 415 --fixed`
- `cwe fuzz 415`
