# CWE-401: Missing Release of Memory after Effective Lifetime

The app requests an unsupported resolution three times, each attempt leaks a DMA buffer.

`dma_alloc` uses `malloc` here and counts the buffers in use, like an instrumented driver in a test.

## Things to try

- `cwe run 401 -p plain`, the driver's counter notices
- `cwe run 401 -p asan`
- `cwe run 401 -p valgrind`
- `cwe tidy 401`, which check fires and why does it hint at the bug?
- `cwe run 401 -p asan --fixed`
