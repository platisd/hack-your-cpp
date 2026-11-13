#include LAB_VARIANT
#include <string>

int main(int argc, char* argv[]) {
    MotorController controller;
    controller.onStatus(StatusFrame{argc > 1 ? std::stoi(argv[1]) : 4});
}
