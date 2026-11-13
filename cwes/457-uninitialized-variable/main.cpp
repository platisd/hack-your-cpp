#include LAB_VARIANT
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
    const Tool tool{static_cast<uint32_t>(argc > 1 ? std::strtoul(argv[1], nullptr, 0) : 0x99)};
    Ecu ecu;
    const auto session = ecu.openSession(tool);
    if (session.canFlash) {
        std::printf("Tool 0x%x may flash the ECU\n", session.toolId);
    } else {
        std::printf("Tool 0x%x may not flash the ECU\n", session.toolId);
    }
}
