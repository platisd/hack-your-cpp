#include LAB_VARIANT
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    const auto offset = static_cast<uint32_t>(argc > 2 ? std::stoul(argv[1]) : UINT32_MAX - 255);
    std::vector<uint8_t> chunk(argc > 2 ? std::stoul(argv[2]) : 256, 0x41);
    auto staging = std::make_unique<FirmwareStaging>();
    const bool accepted = staging->write(offset, chunk);
    std::printf("Chunk at offset %u %s\n", offset, accepted ? "accepted" : "rejected");
}
