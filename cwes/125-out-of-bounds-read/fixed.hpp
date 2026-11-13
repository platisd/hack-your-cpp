#pragma once
#include "types.hpp"
#include <string>

enum class Fault { None, OverVoltage, OverCurrent, OverTemperature };

std::string toString(int faultCode) {
    switch (static_cast<Fault>(faultCode)) {
        case Fault::None: return "None";
        case Fault::OverVoltage: return "OverVoltage";
        case Fault::OverCurrent: return "OverCurrent";
        case Fault::OverTemperature: return "OverTemperature";
    }
    return "Unknown";
}

void MotorController::onStatus(const StatusFrame& frame) {
    if (frame.faultCode != 0) {
        mLog.error("Motor fault: {}", toString(frame.faultCode));
    }
}
