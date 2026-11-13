#pragma once
#include "logger.hpp"
#include <cstdio>
#include <functional>
#include <map>
#include <string>
#include <thread>

struct Message {
    std::string topic;
    std::string payload;
};

class MqttClient {
    std::map<std::string, std::function<void(const Message&)>> mSubscriptions;
public:
    void subscribe(const std::string& topic, std::function<void(const Message&)> callback) {
        mSubscriptions[topic] = std::move(callback);
    }
    void receive(const Message& message) {
        std::jthread network{[this, message] { mSubscriptions.at(message.topic)(message); }};
    }
};

class Heating {
public:
    void onTemperature(double temperature) { std::printf("Heating sees %.1f °C\n", temperature); }
};

class SmartHub {
    MqttClient& mMqtt;
    Heating mHeating;
    [[maybe_unused]] Logger mLog;
public:
    explicit SmartHub(MqttClient& mqtt) : mMqtt{mqtt} {}
    void start();
};
