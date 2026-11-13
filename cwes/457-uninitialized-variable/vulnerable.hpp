#pragma once
#include "types.hpp"

struct DiagnosticSession { uint32_t toolId; bool canFlash; };

class Ecu {
    TrustedTools mTrustedTools;
    bool verify(const Tool& tool) const { return tool.id != 0x30; }
public:
    DiagnosticSession openSession(const Tool& tool);
};

DiagnosticSession Ecu::openSession(const Tool& tool) {
    DiagnosticSession session;
    session.toolId = tool.id;
    if (mTrustedTools.contains(tool.id)) { session.canFlash = verify(tool); }
    return session;
}
