#pragma once
#include <cstdint>

enum class Type { Chat, Invite };

struct Message {
    Type type{};
    uint32_t friendId{};
    uint64_t timestamp{};
};

struct Player {
    uint32_t id{};
    uint64_t lastSeen{};
};
