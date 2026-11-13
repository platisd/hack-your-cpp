#pragma once
#include <array>

struct Calibration { std::array<float, 6> offsets{}; float temperature{}; };

class Eeprom {
    Calibration mCalibration{{0.01F, -0.02F, 0.03F, 0.5F, -0.4F, 0.3F}, 25.0F};
public:
    Calibration& calibration() { return mCalibration; }
};
