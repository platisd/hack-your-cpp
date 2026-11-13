#pragma once
#include "types.hpp"
#include <map>

class Hub {
    std::map<DeviceId, void*> mDevices;
public:
    void add(DeviceId id, void* device) { mDevices[id] = device; }
    void onRename(const Command& command);
};

void Hub::onRename(const Command& command) {
    auto it = mDevices.find(command.id); // std::map<DeviceId, void*>
    if (it != mDevices.end() && command.kind == Kind::Thermometer) {
        static_cast<Thermometer*>(it->second)->setLabel(command.label);
    }
}
