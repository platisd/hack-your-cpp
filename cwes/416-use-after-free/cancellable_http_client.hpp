#pragma once
#include <functional>
#include <map>
#include <string>
#include <utility>
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
    std::map<int, std::function<void(Response)>> mPending;
    int mLastId{};
public:
    class Request {
        HttpClient* mHttp{};
        int mId{};
        void cancel() { if (mHttp != nullptr) { mHttp->mPending.erase(mId); } }
    public:
        Request() = default;
        Request(HttpClient* http, int id) : mHttp{http}, mId{id} {}
        Request(Request&& other) noexcept : mHttp{std::exchange(other.mHttp, nullptr)}, mId{other.mId} {}
        Request& operator=(Request&& other) noexcept {
            cancel();
            mHttp = std::exchange(other.mHttp, nullptr);
            mId = other.mId;
            return *this;
        }
        ~Request() { cancel(); }
    };
    Request postAsync(const std::string&, Payload, std::function<void(Response)> callback) {
        mPending.emplace(++mLastId, std::move(callback));
        return Request{this, mLastId};
    }
    void poll() {
        for (auto& [id, complete] : std::exchange(mPending, {})) { complete(Response{200}); }
    }
};
