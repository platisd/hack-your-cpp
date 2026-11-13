# CWE-416: Use After Free

The config changes while an upload is in progress, the callback writes into the destroyed uploader.

## Things to try

- `cwe run 416 -p plain` looks fine
- `cwe run 416 -p asan` shows where the uploader was freed and where it was used
- `cwe run 416 -p valgrind`
- `cwe tidy 416` stays silent
- `cwe run 416 --fixed -p asan`
