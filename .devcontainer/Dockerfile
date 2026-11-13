FROM ubuntu:26.04

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        g++-15 \
        clang-21 \
        clang-tidy-21 \
        libclang-rt-21-dev \
        lld-21 \
        valgrind \
        gdb \
        python3 \
        git \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/* \
    && ln -s /usr/bin/g++-15 /usr/local/bin/g++ \
    && ln -s /usr/bin/gcc-15 /usr/local/bin/gcc

ENV PATH=/usr/lib/llvm-21/bin:$PATH
