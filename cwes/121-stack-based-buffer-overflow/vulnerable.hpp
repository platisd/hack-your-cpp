#pragma once
#include "types.hpp"
#include <array>
#include <cstdio>
#include <span>

std::string formatReadings(std::span<const Reading> readings) {
    std::array<char, 128> line{};
    for (std::size_t used = 0; const auto& [name, value] : readings) {
        std::size_t remaining = line.size() - used;
        int written = std::snprintf(&line[used], remaining, "%s=%.2f;",
                                        name.c_str(), value);
        used += written;
    }
    return line.data();
} // What if a (compromised) sensor reports long names and they don't fit?
