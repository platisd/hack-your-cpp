#include LAB_VARIANT
#include <cstdio>

int main() {
    HttpClient http;
    TelemetryService service{http};
    service.onConfigChanged(Config{"https://telemetry.example.com"});
    service.upload(Payload{{1, 2, 3}});
    service.onConfigChanged(Config{"https://telemetry2.example.com"});
    http.poll();
    std::puts("Upload completed");
}
