#pragma once
#include "types.hpp"
#include <unordered_map>

class CanGateway {
    std::unordered_map<uint32_t, FrameHandler*> mHandlers;
public:
    void registerHandler(uint32_t canId, FrameHandler& handler) {
        mHandlers[canId] = &handler;
    }
    void onFrame(const CanFrame& frame) {
        mHandlers[frame.id]->handle(frame);
    }
};
