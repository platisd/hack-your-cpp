#pragma once
#include "types.hpp"
#include <algorithm>
#include <cstdint>
#include <optional>
#include <span>

std::optional<AccessPoint> parseSsid(std::span<const uint8_t> element) {
    if (element.size() < 2) { return {}; }
    const auto ssid = element.subspan(2); // Read until the end of span
    AccessPoint ap{};
    if (ssid.size() != element[1] || ssid.size() >= ap.ssid.size()) {
        return {}; // Length field lies or SSID too long
    }
    std::ranges::copy(ssid, ap.ssid.begin()); // or with std::copy
    return ap;
}
