#include LAB_VARIANT

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, std::size_t size) {
    MqttClient mqtt;
    SmartHub hub{mqtt};
    hub.start();
    mqtt.receive(Message{"livingroom/temperature", std::string(reinterpret_cast<const char*>(data), size)});
    return 0;
}
