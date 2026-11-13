#pragma once
#include "types.hpp"
#include <memory>

struct DmaFree {
    void operator()(uint8_t* buffer) const { dma_free(buffer); }
};
class Camera {
    std::unique_ptr<uint8_t, DmaFree> mFrame{dma_alloc(kFrameSize)};
public:
    Camera(Sensor& sensor, Resolution resolution) {
        sensor.configure(resolution); // If this throws, mFrame still freed
    }
}; // No destructor needed
