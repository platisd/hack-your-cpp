#pragma once
#include "types.hpp"

std::vector<uint8_t> Navigator::loadMap(MapFile& file) {
    const auto [columns, rows] = file.read<MapSize>();
    const uint16_t cellCount = columns * rows; // Both are uint16_t
    std::vector<uint8_t> cells(cellCount);
    for (std::size_t row = 0; row < rows; ++row) {
        file.read(&cells[row * columns], columns); // Read one row of cells
    }
    return cells;
}
