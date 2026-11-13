#pragma once
#include "types.hpp"
#include <functional>
#include <unordered_map>

class CanGateway {
    std::unordered_map<uint32_t, std::reference_wrapper<FrameHandler>> mHandlers;
public:
    void registerHandler(uint32_t canId, FrameHandler& handler) {
        mHandlers.insert_or_assign(canId, handler);
    }
    void onFrame(const CanFrame& frame) {
        if (auto it = mHandlers.find(frame.id); it != mHandlers.end()) {
            it->second.get().handle(frame);
        } // std::reference_wrapper has no default, operator[] won't compile
    }
};
