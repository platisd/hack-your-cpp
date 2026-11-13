#pragma once
#include <algorithm>
#include <array>
#include <cstdint>
#include <span>

class FirmwareStaging {
    std::array<uint8_t, 512 * 1024> mImage{};
public:
    bool write(uint32_t offset, std::span<uint8_t> chunk);
};

bool FirmwareStaging::write(uint32_t offset, std::span<uint8_t> chunk) {
    if (offset > mImage.size()) { return false; } // Reject offset past the end
    auto spaceLeft = mImage.size() - offset; // offset <= size so no wrap
    if (chunk.size() > spaceLeft) { return false; }
    std::ranges::copy(chunk, mImage.begin() + offset);
    return true;
}
