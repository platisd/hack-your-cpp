#pragma once
#include "types.hpp"
#include <algorithm>

void Speaker::onPacket(std::span<const uint8_t> packet) {
    std::array<int16_t, 256> samples{};
    auto destination = std::as_writable_bytes(std::span{samples});
    if (packet.size() > destination.size()) { // Compare bytes with bytes
        return;
    }
    std::ranges::copy(std::as_bytes(packet), destination.begin());
    play(samples, packet.size() / sizeof(int16_t));
}
