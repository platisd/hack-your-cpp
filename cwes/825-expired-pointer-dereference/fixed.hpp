#pragma once
#include "types.hpp"
#include <cstddef>
#include <vector>

struct Lobby {
    std::vector<Player> mPlayers{};
    void onMessage(std::size_t from, const Message& msg);
};

void Lobby::onMessage(std::size_t from, const Message& msg) {
    if (msg.type == Type::Invite) {
        mPlayers.push_back(Player{msg.friendId});
    }
    mPlayers.at(from).lastSeen = msg.timestamp;
}
