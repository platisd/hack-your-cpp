#pragma once
#include <array>
#include <cstdint>
#include <cstdio>

struct CanFrame {
    uint32_t id{};
    std::array<uint8_t, 8> data{};
};

class FrameHandler {
public:
    virtual ~FrameHandler() = default;
    virtual void handle(const CanFrame& frame) = 0;
};

class SpeedHandler : public FrameHandler {
public:
    void handle(const CanFrame& frame) override { std::printf("Speed: %d km/h\n", frame.data[0]); }
};
