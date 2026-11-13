# CWE-120: Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')

A beacon says its SSID is 200 bytes long, `parseSsid` believes it.

## Things to try

- `cwe run 120 -p asan -- MyHomeWifi` with a valid SSID
- `cwe run 120 -p asan` with the default 200 byte SSID
- `cwe run 120 -p warnings` and `cwe tidy 120` stay silent
- `cwe fuzz 120` finds it in less than a second
- `cwe fuzz 120 --fixed --time 10`
