#pragma once
#include "logger.hpp"
#include "mqtt.h"
#include <span>

class Bridge {
    mqtt_client client{};
    mqtt_client* mClient{&client};
    Logger mLog;
public:
    void forward(std::span<const uint8_t> payload);
};
