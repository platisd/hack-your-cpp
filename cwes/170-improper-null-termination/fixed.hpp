#pragma once
#include "types.hpp"
#include <array>
#include <string_view>

void GpsLogger::onCommand(Uart& uart) {
    std::array<char, 33> line{}; // One spare byte for the '\0'
    std::size_t length = uart.readLine(std::span{line}.first(32));
    line[length] = '\0'; // Always in bounds, never overwrites the command
    std::string_view command{line.data(), length};
    if (command.starts_with("LOG:")) {
        std::string_view path = command.substr(4);
        mFile = std::fopen(path.data(), "w");
    }
}
