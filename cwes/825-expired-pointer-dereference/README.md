# CWE-825: Expired Pointer Dereference

An invite makes `mPlayers` reallocate while `sender` still refers to the old storage.

The trigger takes the number of invites and the capacity to reserve up front.

## Things to try

- `cwe run 825 -p asan -- 1 2` has room for the friend, nothing reallocates
- `cwe run 825 -p asan -- 1 1` reallocates
- `cwe run 825 -p asan -- 10 16`, how many invites until it breaks?
- `cwe run 825 -p stl-debug` stays silent, now change `Player& sender` to an iterator from `mPlayers.begin() + from`
- `cwe fuzz 825`
