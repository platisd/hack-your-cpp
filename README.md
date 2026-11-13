# hack-your-cpp

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/platisd/hack-your-cpp)

Code from my (currently unpublished) talk *The NSA was right: 20 ways your C++ can be hacked*.<br>
Build each example yourself, run it under sanitizers, hardening, Valgrind,
clang-tidy and a fuzzer, and see what each tool catches and what it misses.

## Getting started

Open the repository in GitHub Codespaces, or in VS Code with the
[Dev Containers](https://code.visualstudio.com/docs/devcontainers/containers) extension.
The container comes with `GCC 15`, `Clang 21`, `clang-tidy`, `libFuzzer` and `Valgrind`.

```bash
cwe list              # all CWEs from the talk
cwe show 121          # what to try for CWE-121
cwe run 121           # build and run CWE-121 with AddressSanitizer
```

Every command prints the exact compiler command it runs, so you can copy it and change it.

### Running outside the container

Build the docker image:

```bash
docker build -t hack-your-cpp .devcontainer
```

Run a shell in the container:

```bash
docker run --rm -it \
  -v "$PWD":/work -w /work \
  --user "$(id -u):$(id -g)" \
  --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
  hack-your-cpp bash -c 'export PATH=/work:$PATH; exec bash'
```

## Commands

```bash
cwe run 121 -p fortify3                # pick a profile
cwe run 121 -p asan --cc clang -O 1    # pick a compiler and an optimization level
cwe run 121 -p asan -p ubsan           # combine profiles
cwe run 121 --fixed -p asan            # the fixed variant, same input
cwe run 121 -p plain -- 10             # your own input for the trigger
cwe run 121 -p plain --flag=-fsanitize=bounds

cwe tidy 170                           # clang-tidy with the checks relevant to the CWE
cwe tidy 170 --fixed
cwe tidy 170 --checks='bugprone-*,cert-*'

cwe fuzz 120                           # libFuzzer with AddressSanitizer, 30 seconds
cwe fuzz 120 --reproduce build/120-classic-buffer-overflow/fuzz-vulnerable/crash-...

cwe matrix 121                         # every tool against what it's expected to report
cwe matrix                             # all CWEs
cwe profiles                           # all profiles and their flags
```

In VS Code, the same commands are available under *Terminal → Run Task*.

## Profiles

Profiles are named sets of flags in [profiles.toml](profiles.toml), e.g. `asan`, `ubsan`, `msan`, `tsan`,
`hardened`, `fortify2`, `stack-protector`, `warnings`, `analyzer` and `valgrind`.

Every build starts from a baseline without any hardening:

```
-std=c++23 -g -U_FORTIFY_SOURCE -fno-stack-protector -D_GLIBCXX_NO_ASSERTIONS
```

Ubuntu's GCC enables `_FORTIFY_SOURCE=3` and `-fstack-protector-strong` by default,
and libstdc++ 15 enables `_GLIBCXX_ASSERTIONS` in unoptimized builds.
The baseline turns them off, so you see what each profile adds.

## What's in a CWE

```
cwes/121-stack-based-buffer-overflow/
├── README.md        what to try
├── cwe.toml         trigger input and what each tool is expected to report
├── vulnerable.hpp   the code from the slides
├── fixed.hpp        the fix from the slides
├── types.hpp        what the slides leave out
├── main.cpp         triggers the bug, built against either variant
└── fuzz.cpp         libFuzzer target, where it makes sense
```

Change the code and run it again, that's the point.
`cwe matrix` tells you if your change made a tool catch or miss something.

## Expectations

Each `cwe.toml` lists what a tool is expected to report:

```toml
[[expect]]
cc = ["gcc", "clang"]           # default: gcc
profiles = ["asan"]
detects = "stack-buffer-overflow"

[[expect]]
profiles = ["fortify2"]
misses = "buffer overflow detected"

[[expect]]
variant = "fixed"
tool = "tidy"                   # or "fuzz", default: run the trigger
silent = true
```

- `detects`: the output matches the regular expression
- `misses`: the output doesn't match it, the program may still crash
- `silent`: exits with `0`, without warnings or errors

CI runs `cwe matrix` in the dev container on every push.

## Troubleshooting

ThreadSanitizer and MemorySanitizer need to disable ASLR on kernels with high ASLR entropy.
The dev container allows that with `--security-opt seccomp=unconfined`.
Outside the container, run `sudo sysctl vm.mmap_rnd_bits=28` if they fail with
`FATAL: ThreadSanitizer: unexpected memory mapping` or similar.
