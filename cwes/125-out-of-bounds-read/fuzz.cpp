#include LAB_VARIANT
#include <cstdint>
#include <cstring>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
    StatusFrame frame{};
    std::memcpy(&frame.faultCode, data, std::min(size, sizeof(frame.faultCode)));
    MotorController{}.onStatus(frame);
    return 0;
}
