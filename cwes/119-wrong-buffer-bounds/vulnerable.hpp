#pragma once
#include "types.hpp"
#include <cstring>

void Speaker::onPacket(std::span<const uint8_t> packet) { // From a phone
    std::array<int16_t, 256> samples{}; // 16-bit audio
    const auto sampleCount = packet.size() / sizeof(int16_t);
    if (sampleCount > sizeof(samples)) {
        return; // Too many samples
    }
    std::memcpy(samples.data(), packet.data(), packet.size());
    play(samples, sampleCount);
}
