#pragma once
#include "types.hpp"

void SmartHub::start() {
    // The MQTT client calls this lambda on its own network thread
    mMqtt.subscribe("livingroom/temperature", [this](const Message& msg) {
        double temperature = std::stod(msg.payload); // E.g. "21.5"
        mHeating.onTemperature(temperature);
    });
}
