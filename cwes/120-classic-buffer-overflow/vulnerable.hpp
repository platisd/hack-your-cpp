#pragma once
#include "types.hpp"
#include <cstdint>
#include <cstring>
#include <span>

AccessPoint parseSsid(std::span<const uint8_t> element) { // From a Wi-Fi beacon
    AccessPoint ap{};
    const uint8_t length = element[1]; // [ID][Length][SSID...]
    std::memcpy(ap.ssid.data(), &element[2], length);
    return ap;
}
