#pragma once
#include <array>
#include <cstdint>

class FaultLog {
    std::array<uint32_t, 16> mCountPerFault{};
public:
    void record(int faultCode) { // Parsed from a diagnostic frame
        if (faultCode < static_cast<int>(mCountPerFault.size())) {
            ++mCountPerFault[faultCode];
        }
    }
};
