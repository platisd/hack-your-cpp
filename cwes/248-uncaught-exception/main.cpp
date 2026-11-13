#include LAB_VARIANT

int main(int argc, char* argv[]) {
    MqttClient mqtt;
    SmartHub hub{mqtt};
    hub.start();
    mqtt.receive(Message{"livingroom/temperature", "21.5"});
    mqtt.receive(Message{"livingroom/temperature", argc > 1 ? argv[1] : "N/A"});
    std::puts("The hub is still running");
}
