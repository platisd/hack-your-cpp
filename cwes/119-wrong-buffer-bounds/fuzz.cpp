#include LAB_VARIANT

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    Speaker{}.onPacket({data, size});
    return 0;
}
