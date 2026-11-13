#pragma once
#include <algorithm>
#include <cstdio>
#include <span>
#include <string>

class Uart {
    std::string mInput;
public:
    explicit Uart(std::string input) : mInput{std::move(input)} {}
    std::size_t readLine(std::span<char> buffer) {
        const auto length = std::min(buffer.size(), mInput.size());
        std::copy_n(mInput.begin(), length, buffer.begin());
        return length;
    }
};

class GpsLogger {
    std::FILE* mFile{};
public:
    void onCommand(Uart& uart);
    bool logging() const { return mFile != nullptr; }
    ~GpsLogger() { if (mFile != nullptr) { std::fclose(mFile); } }
};
