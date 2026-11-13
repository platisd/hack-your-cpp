#include LAB_VARIANT
#include <cstring>
#include <memory>
#include <vector>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    uint32_t offset{};
    if (size < sizeof(offset)) { return 0; }
    std::memcpy(&offset, data, sizeof(offset));
    std::vector<uint8_t> chunk(data + sizeof(offset), data + size);
    static auto staging = std::make_unique<FirmwareStaging>();
    staging->write(offset, chunk);
    return 0;
}
