#pragma once
#include "types.hpp"
#include <span>

class Imu {
    Eeprom& mEeprom;
public:
    explicit Imu(Eeprom& eeprom) : mEeprom{eeprom} {}
    std::span<float> offsets();
};

std::span<float> Imu::offsets() {
    auto& calibration = mEeprom.calibration(); // No copy
    return calibration.offsets;
}
