#include LAB_VARIANT
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    const std::string ssid = argc > 1 ? argv[1] : std::string(200, 'A');
    std::vector<uint8_t> element(ssid.size() + 2);
    element[1] = static_cast<uint8_t>(ssid.size());
    std::ranges::copy(ssid, element.begin() + 2);
    parseSsid(element);
    std::printf("Parsed an SSID of %zu bytes\n", ssid.size());
}
