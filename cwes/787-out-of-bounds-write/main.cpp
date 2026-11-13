#include LAB_VARIANT
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    const int pushes = argc > 1 ? std::stoi(argv[1]) : 100;
    TelemetryBuffer buffer;
    for (int i = 0; i < pushes; ++i) {
        buffer.push(Sample{static_cast<std::uint32_t>(i), 21.5F});
    }
    std::printf("Pushed %d samples\n", pushes);
}
