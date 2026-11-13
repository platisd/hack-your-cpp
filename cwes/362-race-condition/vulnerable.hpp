#pragma once
#include "types.hpp"
#include <memory>

struct Firewall {
    std::shared_ptr<RuleSet> mRules{};
    void reload(RuleSet rules) { // Admin thread, e.g. to block an IP address
        mRules = std::make_shared<RuleSet>(std::move(rules));
    }
    Verdict check(const Packet& packet) { // Packet threads
        return mRules->evaluate(packet);
    }
};
