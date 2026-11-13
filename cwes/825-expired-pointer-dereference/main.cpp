#include LAB_VARIANT
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    const int invites = argc > 1 ? std::stoi(argv[1]) : 1;
    Lobby lobby;
    lobby.mPlayers.reserve(argc > 2 ? std::stoul(argv[2]) : 1);
    lobby.mPlayers.push_back(Player{1});
    for (int i = 0; i < invites; ++i) {
        lobby.onMessage(0, Message{Type::Invite, static_cast<uint32_t>(i + 2), 0x4141414141414141});
    }
    std::printf("%zu players in the lobby\n", lobby.mPlayers.size());
}
