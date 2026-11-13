#include LAB_VARIANT
#include <cstring>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    SpeedHandler speed;
    CanGateway gateway;
    gateway.registerHandler(0x100, speed);
    CanFrame frame{};
    std::memcpy(&frame.id, data, std::min(size, sizeof(frame.id)));
    gateway.onFrame(frame);
    return 0;
}
