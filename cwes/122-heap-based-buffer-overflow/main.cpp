#include LAB_VARIANT
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    const MapSize size{
        static_cast<uint16_t>(argc > 2 ? std::stoul(argv[1]) : 400),
        static_cast<uint16_t>(argc > 2 ? std::stoul(argv[2]) : 300),
    };
    std::vector<uint8_t> bytes(sizeof(size) + std::size_t{size.columns} * size.rows, 1);
    std::memcpy(bytes.data(), &size, sizeof(size));
    MapFile file{std::move(bytes)};
    const auto cells = Navigator{}.loadMap(file);
    std::printf("Loaded a map of %zu cells\n", cells.size());
}
