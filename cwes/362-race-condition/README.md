# CWE-362: Concurrent Execution using Shared Resource with Improper Synchronization ('Race Condition')

An admin thread reloads the rules while four packet threads check packets.

The trigger takes the number of reloads and checks per thread.

## Things to try

- `cwe run 362 -p plain` a few times, it often survives
- `cwe run 362 -p tsan`
- `cwe run 362 -p tsan -- 1`, do the threads still overlap?
- `cwe run 362 -p asan` a few times, sometimes it catches the consequence
- `cwe run 362 --fixed -p tsan`
