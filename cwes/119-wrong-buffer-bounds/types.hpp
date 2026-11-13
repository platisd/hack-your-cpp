#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <span>

class Speaker {
public:
    void onPacket(std::span<const uint8_t> packet);
    void play(const std::array<int16_t, 256>& samples, std::size_t count) {
        std::printf("Playing %zu samples, first is %d\n", count, samples[0]);
    }
};
