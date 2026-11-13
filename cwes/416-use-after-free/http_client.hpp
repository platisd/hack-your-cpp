#pragma once
#include <functional>
#include <utility>
#include <string>
#include <vector>

struct Config {
    std::string endpoint;
};

struct Payload {
    std::vector<unsigned char> bytes;
};

struct Response {
    int status{};
};

class HttpClient {
    std::vector<std::function<void()>> mPending;
public:
    void postAsync(const std::string&, Payload, std::function<void(Response)> callback) {
        mPending.emplace_back([callback = std::move(callback)] { callback(Response{200}); });
    }
    void poll() {
        for (auto& complete : std::exchange(mPending, {})) { complete(); }
    }
};
