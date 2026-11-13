#pragma once
#include <cstdint>
#include <cstring>
#include <vector>

struct MapSize {
    uint16_t columns{};
    uint16_t rows{};
};

class MapFile {
    std::vector<uint8_t> mBytes;
    std::size_t mPosition{};
public:
    explicit MapFile(std::vector<uint8_t> bytes) : mBytes{std::move(bytes)} {}
    template <typename T>
    T read() {
        T value{};
        read(reinterpret_cast<uint8_t*>(&value), sizeof(T));
        return value;
    }
    void read(uint8_t* destination, std::size_t count) {
        std::memcpy(destination, mBytes.data() + mPosition, count);
        mPosition += count;
    }
};

class Navigator {
public:
    std::vector<uint8_t> loadMap(MapFile& file);
};
