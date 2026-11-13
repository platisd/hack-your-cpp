#pragma once
#include "types.hpp"
#include <array>
#include <string_view>

void GpsLogger::onCommand(Uart& uart) { // E.g. "LOG:track.gpx"
    std::array<char, 32> line{};
    std::size_t length = uart.readLine(line); // Reads up to line.size()
    std::string_view command{line.data(), length};
    if (command.starts_with("LOG:")) {
        std::string_view path = command.substr(4); // "track.gpx"
        mFile = std::fopen(path.data(), "w");
    }
}
