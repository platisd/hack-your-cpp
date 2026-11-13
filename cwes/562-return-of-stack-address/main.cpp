#include LAB_VARIANT
#include <cstdio>

[[gnu::noinline]] float signFirmware() {
    volatile float signingKey[8]{1234.5F, 2345.6F, 3456.7F, 4567.8F,
                                 5678.9F, 6789.1F, 7891.2F, 8912.3F};
    return signingKey[0];
}

int main() {
    Eeprom eeprom;
    Imu imu{eeprom};
    const auto offsets = imu.offsets();
    signFirmware();
    for (std::size_t i = 0; i < offsets.size(); ++i) {
        std::printf("%.2f ", offsets[i]);
    }
    std::puts("");
}
