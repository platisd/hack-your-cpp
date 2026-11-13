# CWE-134: Use of Externally-Controlled Format String

A hacked translation database replaces `%.1f` with `%s`.

The trigger takes the translated label.

## Things to try

- `cwe run 134 -p unprotected -- 'Temperatur: %.1f °C'` is a valid translation
- `cwe run 134 -p unprotected`, where does the text after `Temperatur:` come from?
- `cwe run 134 -p unprotected -- '%p %p %p %p'`
- `cwe run 134 -p fortify2 -- 'Temperatur: %n °C'`
- `cwe run 134 -p warnings`, then remove `-Wformat-nonliteral` from the `warnings` profile
- `cwe run 134 --fixed -p asan -- '{} {} {}'` and `-- '{:.2f} °C'`
