# CWE-170: Improper Null Termination

The command is exactly 32 bytes, so `line` has no room left for a `'\0'`.

The files that `fopen` creates end up in the build directory.

## Things to try

- `cwe run 170 -p asan -- LOG:track.gpx`, then the default 32 byte command
- `cwe run 170 -p unprotected`, then `ls` the build directory, what is the file called?
- `cwe run 170 -p asan -- LOG:abcdefghijklmnopqrstuvwxyz1` and with one more character
- `cwe tidy 170` and `cwe tidy 170 --fixed`
