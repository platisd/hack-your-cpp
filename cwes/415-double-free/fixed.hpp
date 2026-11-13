#pragma once
#include "types.hpp"
#include <memory>

using MqttMsg = std::unique_ptr<mqtt_msg, decltype(&mqtt_msg_free)>;

void Bridge::forward(std::span<const uint8_t> payload) {
    MqttMsg msg{mqtt_msg_new(payload.data(), payload.size()), &mqtt_msg_free};
    if (mqtt_publish(mClient, msg.release()) != 0) { // Always release
        mLog.warn("Dropped message of {} bytes", payload.size());
    }
}
