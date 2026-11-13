#pragma once
#include "types.hpp"
#include <map>
#include <variant>

using Device = std::variant<Thermometer*, Camera*>; // Types are known

class Hub {
    std::map<DeviceId, Device> mDevices;
public:
    void add(DeviceId id, Device device) { mDevices.insert_or_assign(id, device); }
    void onRename(const Command& command);
};

void Hub::onRename(const Command& command) {
    auto it = mDevices.find(command.id);  // std::map<DeviceId, Device>
    if (it == mDevices.end()) { return; } // Unknown device
    if (auto* thermometer = std::get_if<Thermometer*>(&it->second)) {
        (*thermometer)->setLabel(command.label);
    } // command.kind ignored
}
