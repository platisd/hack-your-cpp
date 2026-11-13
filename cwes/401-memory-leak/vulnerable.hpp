#pragma once
#include "types.hpp"

class Camera {
    uint8_t* mFrame{dma_alloc(kFrameSize)};
public:
    Camera(Sensor& sensor, Resolution resolution) { // Chosen in the app
        sensor.configure(resolution); // Throws if not supported
    }
    ~Camera() { dma_free(mFrame); }
};
