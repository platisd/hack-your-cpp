#include LAB_VARIANT
#include <cstdio>
#include <string>

int main(int argc, char* argv[]) {
    FaultLog log;
    log.record(argc > 1 ? std::stoi(argv[1]) : -1);
    std::puts("Recorded the fault");
}
