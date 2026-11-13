#pragma once
#include "types.hpp"
#include <span>

class Imu {
    Eeprom& mEeprom; // Eeprom::calibration() returns Calibration&
public:
    explicit Imu(Eeprom& eeprom) : mEeprom{eeprom} {}
    std::span<float> offsets() {
        auto calibration = mEeprom.calibration();
        return calibration.offsets;
    }
};
