#pragma once
#include "types.hpp"
#include <memory>

// C library: takes ownership of `msg`, frees it even when it fails
extern "C" int mqtt_publish(mqtt_client* client, mqtt_msg* msg);
using MqttMsg = std::unique_ptr<mqtt_msg, decltype(&mqtt_msg_free)>;

void Bridge::forward(std::span<const uint8_t> payload) { // From a sensor
    MqttMsg msg{mqtt_msg_new(payload.data(), payload.size()), &mqtt_msg_free};
    if (mqtt_publish(mClient, msg.get()) == 0) {
        msg.release(); // Published, the library owns it now
    }
}
