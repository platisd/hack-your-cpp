#pragma once
#include "logger.hpp"

struct StatusFrame {
    int faultCode{};
};

class MotorController {
    Logger mLog;
public:
    void onStatus(const StatusFrame& frame);
};
