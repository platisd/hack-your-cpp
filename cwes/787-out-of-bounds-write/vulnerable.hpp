#pragma once
#include "types.hpp"
#include <cstddef>

class TelemetryBuffer { // Keeps the latest samples until uploaded
    Sample mSamples[64]{};
    std::size_t mHead{0};
public:
    void push(const Sample& sample) {
        mSamples[mHead] = sample;
        ++mHead;
        if (mHead > 64) { mHead = 0; }
    }
};
