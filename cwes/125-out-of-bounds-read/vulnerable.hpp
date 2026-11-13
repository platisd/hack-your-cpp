#pragma once
#include "types.hpp"
#include <array>
#include <string>

enum class Fault { None, OverVoltage, OverCurrent, OverTemperature };
const std::array<std::string, 4> kFaultNames{
    "None", "OverVoltage", "OverCurrent", "OverTemperature"};

void MotorController::onStatus(const StatusFrame& frame) {
    if (frame.faultCode != 0) {
        mLog.error("Motor fault: {}", kFaultNames[frame.faultCode]);
    }
}
