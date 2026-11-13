#include LAB_VARIANT
#include <cstdio>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    const std::size_t nameLength = argc > 1 ? std::stoul(argv[1]) : 40;
    const std::vector<Reading> readings{
        {std::string(nameLength, 't'), 21.5},
        {std::string(nameLength, 'h'), 45.0},
        {std::string(nameLength, 'p'), 1013.2},
        {std::string(nameLength, 'c'), 412.0},
    };
    formatReadings(readings);
    std::puts("Formatted the readings");
}
