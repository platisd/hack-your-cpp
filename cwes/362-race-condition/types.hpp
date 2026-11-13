#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>

enum class Verdict { Accept, Drop };

struct Packet {
    uint32_t source{};
};

struct RuleSet {
    std::vector<uint32_t> blocked;
    Verdict evaluate(const Packet& packet) const {
        return std::ranges::contains(blocked, packet.source) ? Verdict::Drop : Verdict::Accept;
    }
};
