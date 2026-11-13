#pragma once
#include "types.hpp"

std::vector<uint8_t> Navigator::loadMap(MapFile& file) {
    const auto [columns, rows] = file.read<MapSize>(); // Both uint16_t
    const auto cellCount = std::size_t{columns} * std::size_t{rows};
    std::vector<uint8_t> cells(cellCount);
    for (std::size_t row = 0; row < rows; ++row) {
        file.read(&cells[row * columns], columns);
    }
    return cells;
}
