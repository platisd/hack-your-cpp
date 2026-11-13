#pragma once
#include <array>

struct AccessPoint {
    std::array<char, 33> ssid{}; // SSIDs are at most 32 bytes, plus '\0'
};
