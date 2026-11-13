#pragma once
#include <format>
#include <print>
#include <cstdio>

class Logger {
public:
    template <typename... Args>
    void error(std::format_string<Args...> format, Args&&... args) {
        std::println(stderr, "[error] {}", std::format(format, std::forward<Args>(args)...));
    }
    template <typename... Args>
    void warn(std::format_string<Args...> format, Args&&... args) {
        std::println(stderr, "[warn] {}", std::format(format, std::forward<Args>(args)...));
    }
};
