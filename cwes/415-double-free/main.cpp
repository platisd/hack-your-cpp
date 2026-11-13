#include LAB_VARIANT
#include <cstdio>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    const std::vector<uint8_t> payload(argc > 1 ? std::stoul(argv[1]) : 1024, 0x42);
    Bridge bridge;
    bridge.forward(payload);
    std::printf("Forwarded %zu bytes\n", payload.size());
}
