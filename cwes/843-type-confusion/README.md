# CWE-843: Access of Resource Using Incompatible Type

The app renames device `2` as a thermometer, but it's the camera.

The trigger takes the device ID, `1` is the thermometer.

## Things to try

- `cwe run 843 -p plain -- 1`, then the default `2`
- `cwe run 843 -p asan` and `cwe run 843 -p ubsan` stay silent, the memory is valid
- Make `setLabel` and `setPassword` `virtual`, then `cwe run 843 --cc clang -p vptr` and `-p cfi`
- `cwe tidy 843` stays silent
