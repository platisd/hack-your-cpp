# CWE-248: Uncaught Exception

A dying sensor sends `"N/A"`, `std::stod` throws on the MQTT client's thread.

## Things to try

- `cwe run 248 -p unprotected -- 19.0` and `cwe run 248 -p unprotected`
- `cwe run 248 -p unprotected -- 1e999`, which exception is it now?
- `cwe tidy 248` stays silent
- `cwe fuzz 248`
- Call `std::set_terminate` in `main.cpp` to log something before aborting
- Replace `std::stod` with `std::from_chars` in `fixed.hpp`
