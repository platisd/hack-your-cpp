#pragma once
#include "types.hpp"

void SmartHub::start() {
    mMqtt.subscribe("livingroom/temperature", [this](const Message& msg) {
        try {
            double temperature = std::stod(msg.payload);
            mHeating.onTemperature(temperature);
        } catch (const std::exception& e) { // Ignore the bad reading
            mLog.warn("Ignoring '{}': {}", msg.payload, e.what());
        }
    });
}
