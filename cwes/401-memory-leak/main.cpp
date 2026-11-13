#include LAB_VARIANT
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    const int attempts = argc > 1 ? std::stoi(argv[1]) : 3;
    Sensor sensor;
    { Camera camera{sensor, Resolution::VGA}; }
    for (int i = 0; i < attempts; ++i) {
        try {
            Camera camera{sensor, Resolution::FullHD};
        } catch (const std::exception& e) {
            std::printf("Camera failed: %s\n", e.what());
        }
    }
    std::printf("DMA buffers in use: %d\n", gDmaBuffersInUse);
    return gDmaBuffersInUse == 0 ? 0 : 1;
}
