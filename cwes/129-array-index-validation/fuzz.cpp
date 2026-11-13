#include LAB_VARIANT
#include <cstring>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    int faultCode{};
    std::memcpy(&faultCode, data, std::min(size, sizeof(faultCode)));
    FaultLog log;
    log.record(faultCode);
    return 0;
}
