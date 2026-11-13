#pragma once
#include <cstdint>
#include <string>
#include <string_view>

using DeviceId = uint32_t;

enum class Kind { Thermometer, Camera };
struct Thermometer { std::string mLabel; void setLabel(std::string_view label) { mLabel = label; } };
struct Camera { std::string mPassword; void setPassword(std::string_view password) { mPassword = password; } };
struct Command { Kind kind; DeviceId id; std::string label; }; // From an app
