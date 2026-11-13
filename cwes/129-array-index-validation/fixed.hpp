#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

class FaultLog {
    std::array<uint32_t, 16> mCountPerFault{};
public:
    void record(int faultCode);
};

void FaultLog::record(int faultCode) {
    if (faultCode < 0 ||
          static_cast<std::size_t>(faultCode) >= mCountPerFault.size()) {
        return; // Unknown fault code, too high or too low
    }
    ++mCountPerFault[faultCode];
}
