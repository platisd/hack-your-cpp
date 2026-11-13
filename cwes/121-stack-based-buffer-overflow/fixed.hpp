#pragma once
#include "types.hpp"
#include <array>
#include <cstdio>
#include <optional>
#include <span>

std::optional<std::string> formatReadings(std::span<const Reading> readings) {
    std::array<char, 128> line{};
    for (std::size_t used = 0; const auto& [name, value] : readings) {
        std::size_t remaining = line.size() - used;
        int written = std::snprintf(&line[used], remaining, "%s=%.2f;",
                                    name.c_str(), value);
        if (written < 0 || static_cast<std::size_t>(written) >= remaining) {
            return {}; // snprintf error or output didn't fit
        }
        used += static_cast<std::size_t>(written);
    }
    return line.data();
}
