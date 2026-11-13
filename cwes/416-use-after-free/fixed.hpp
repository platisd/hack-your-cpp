#pragma once
#include "cancellable_http_client.hpp"
#include <memory>

class TelemetryUploader {
    HttpClient& mHttp;
    Config mConfig;
    int mLastStatus{};
    HttpClient::Request mPendingUpload; // Cancels request in its destructor
public:
    TelemetryUploader(HttpClient& http, Config config) : mHttp{http}, mConfig{std::move(config)} {}
    void upload(Payload payload) {
        mPendingUpload = mHttp.postAsync(mConfig.endpoint, std::move(payload),
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
