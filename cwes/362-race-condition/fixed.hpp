#pragma once
#include "types.hpp"
#include <atomic>
#include <memory>

class Firewall {
    std::atomic<std::shared_ptr<RuleSet>> mRules{}; // C++20
public:
    void reload(RuleSet rules) {
        mRules = std::make_shared<RuleSet>(std::move(rules));
    }
    Verdict check(const Packet& packet) {
        return mRules.load()->evaluate(packet); // Copy lives until the ;
    }
};
