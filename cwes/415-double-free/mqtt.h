#pragma once
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>

extern "C" {

struct mqtt_client {
    std::size_t maxPayload{256};
};

struct mqtt_msg {
    std::size_t size;
    std::uint8_t* payload;
};

inline mqtt_msg* mqtt_msg_new(const std::uint8_t* payload, std::size_t size) {
    auto* msg = static_cast<mqtt_msg*>(std::malloc(sizeof(mqtt_msg) + size));
    msg->size = size;
    msg->payload = reinterpret_cast<std::uint8_t*>(msg + 1);
    std::memcpy(msg->payload, payload, size);
    return msg;
}

inline void mqtt_msg_free(mqtt_msg* msg) {
    std::free(msg);
}

inline int mqtt_publish(mqtt_client* client, mqtt_msg* msg) {
    const int result = msg->size > client->maxPayload ? -1 : 0;
    mqtt_msg_free(msg);
    return result;
}
}
