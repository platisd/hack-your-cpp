#pragma once
#include <algorithm>
#include <array>
#include <cstdint>

struct Tool {
    uint32_t id{};
};

class TrustedTools {
    std::array<uint32_t, 3> mIds{0x10, 0x20, 0x30};
public:
    bool contains(uint32_t id) const { return std::ranges::find(mIds, id) != mIds.end(); }
};
