#include LAB_VARIANT

int main(int argc, char* argv[]) {
    Uart uart{argc > 1 ? argv[1] : "LOG:a-really-long-track-name.gpx"};
    GpsLogger logger;
    logger.onCommand(uart);
    std::printf("Logging: %s\n", logger.logging() ? "yes" : "no");
}
