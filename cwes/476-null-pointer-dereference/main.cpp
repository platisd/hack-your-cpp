#include LAB_VARIANT
#include <string>

int main(int argc, char* argv[]) {
    SpeedHandler speed;
    CanGateway gateway;
    gateway.registerHandler(0x100, speed);
    gateway.onFrame(CanFrame{0x100, {50}});
    const auto id = argc > 1 ? std::stoul(argv[1], nullptr, 0) : 0x200;
    gateway.onFrame(CanFrame{static_cast<uint32_t>(id), {}});
}
