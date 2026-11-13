#pragma once
#include "types.hpp"
#include <array>
#include <cstddef>

class TelemetryBuffer {
    std::array<Sample, 64> mSamples{};
    std::size_t mHead{0};
public:
    void push(const Sample& sample) {
        mSamples.at(mHead) = sample; // Or check mHead < mSamples.size()
        mHead = (mHead + 1) % mSamples.size();
    }
};
