#pragma once
#include "types.hpp"
#include <cstddef>
#include <vector>

struct Lobby { // Game server, players send messages over the network
    std::vector<Player> mPlayers{};
    void onMessage(std::size_t from, const Message& msg) {
        Player& sender = mPlayers.at(from);
        if (msg.type == Type::Invite) { // Sender brings in a friend
            mPlayers.push_back(Player{msg.friendId});
        }
        sender.lastSeen = msg.timestamp;
    }
};
