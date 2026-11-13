#pragma once
#include "http_client.hpp"
#include <memory>

struct TelemetryUploader {
    HttpClient& mHttp; // Some shared resource that outlives this class
    Config mConfig;
    int mLastStatus{};
    void upload(Payload payload) {
        mHttp.postAsync(mConfig.endpoint, std::move(payload),
                        [this](Response r) { mLastStatus = r.status; });
    }
};

class TelemetryService {
    HttpClient& mHttp;
    std::unique_ptr<TelemetryUploader> mUploader;
public:
    explicit TelemetryService(HttpClient& http) : mHttp{http} {}
    void onConfigChanged(Config config);
    void upload(Payload payload) { mUploader->upload(std::move(payload)); }
};

void TelemetryService::onConfigChanged(Config config) {
    mUploader = std::make_unique<TelemetryUploader>(mHttp, std::move(config));
}
