#include LAB_VARIANT

int main() {
    std::array<uint8_t, 800> packet{};
    packet.fill(0x41);
    Speaker{}.onPacket(packet);
}
