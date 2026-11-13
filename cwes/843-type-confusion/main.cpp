#include LAB_VARIANT
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    Thermometer thermometer{"Living room"};
    Camera camera{"correct horse battery staple"};
    Hub hub;
    hub.add(1, &thermometer);
    hub.add(2, &camera);
    hub.onRename(Command{Kind::Thermometer, static_cast<DeviceId>(argc > 1 ? std::stoul(argv[1]) : 2), "hunter2"});
    std::printf("Thermometer label: %s\n", thermometer.mLabel.c_str());
    std::printf("Camera password: %s\n", camera.mPassword.c_str());
}
