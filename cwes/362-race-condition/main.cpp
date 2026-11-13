#include LAB_VARIANT
#include <cstdio>
#include <string>
#include <thread>
#include <vector>

int main(int argc, char* argv[]) {
    const int reloads = argc > 1 ? std::stoi(argv[1]) : 10000;
    Firewall firewall;
    firewall.reload(RuleSet{{0x0A000001}});
    std::jthread admin{[&] {
        for (int i = 0; i < reloads; ++i) {
            firewall.reload(RuleSet{{0x0A000001, static_cast<uint32_t>(i)}});
        }
    }};
    std::vector<std::jthread> packetThreads;
    for (int t = 0; t < 4; ++t) {
        packetThreads.emplace_back([&] {
            for (int i = 0; i < reloads; ++i) {
                firewall.check(Packet{static_cast<uint32_t>(i)});
            }
        });
    }
    packetThreads.clear();
    admin.join();
    std::puts("Firewall survived");
}
