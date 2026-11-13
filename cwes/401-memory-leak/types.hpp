#pragma once
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

inline int gDmaBuffersInUse{0};
inline uint8_t* dma_alloc(std::size_t size) {
    ++gDmaBuffersInUse;
    return static_cast<uint8_t*>(std::malloc(size));
}
inline void dma_free(uint8_t* buffer) {
    --gDmaBuffersInUse;
    std::free(buffer);
}

constexpr std::size_t kFrameSize{640 * 480 * 2};

enum class Resolution { VGA, HD, FullHD };

class Sensor {
public:
    void configure(Resolution resolution) {
        if (resolution != Resolution::VGA) { throw std::invalid_argument{"Unsupported resolution"}; }
    }
};
