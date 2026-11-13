#include LAB_VARIANT

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    Lobby lobby;
    lobby.mPlayers.push_back(Player{1});
    for (std::size_t i = 0; i < size; ++i) {
        const auto type = data[i] % 2 == 0 ? Type::Chat : Type::Invite;
        lobby.onMessage(data[i] % lobby.mPlayers.size(), Message{type, data[i], i});
    }
    return 0;
}
