#pragma once
#include <algorithm>
#include <array>
#include <cstdint>
#include <span>

class FirmwareStaging { // Collects an OTA update before verifying it
    std::array<uint8_t, 512 * 1024> mImage{};
public:
    bool write(uint32_t offset, std::span<uint8_t> chunk) {
        uint32_t end = offset + chunk.size(); // Both server input
        if (end > mImage.size()) { return false; }
        std::ranges::copy(chunk, mImage.begin() + offset);
        return true;
    }
};
