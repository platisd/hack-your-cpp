#pragma once
#include "types.hpp"
#include <format>

void Thermostat::render(double temperature) {
    const std::string& label = mTranslations.get("temperature"); // "{:.1f} °C"
    try {
        mDisplay.show(std::vformat(label, std::make_format_args(temperature)));
    } catch (const std::format_error&) {
        mDisplay.show(std::format("{:.1f} °C", temperature)); // Fallback
    }
}
