#pragma once
#include "types.hpp"

struct DiagnosticSession {
    DiagnosticSession(uint32_t id, bool flash) : toolId{id}, canFlash{flash} {}
    uint32_t toolId{};
    bool canFlash{false}; // Deny by default
};

class Ecu {
    TrustedTools mTrustedTools;
    bool verify(const Tool& tool) const { return tool.id != 0x30; }
public:
    DiagnosticSession openSession(const Tool& tool);
};

DiagnosticSession Ecu::openSession(const Tool& tool) {
    const bool isTrusted = mTrustedTools.contains(tool.id);
    return DiagnosticSession{tool.id, isTrusted && verify(tool)};
}
