#pragma once
#include "types.hpp"
#include <array>

void Thermostat::render(double temperature) {
    const std::string& label = mTranslations.get("temp"); // "Temperature: %.1f °C"
    std::array<char, 64> line{};
    std::snprintf(line.data(), line.size(), label.c_str(), temperature);
    mDisplay.show(line.data());
}
