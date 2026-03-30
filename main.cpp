#include "application.hpp"
#include "logger.hpp"

int main(int argc, char* argv[]) {
    Logger::initialize();
    Application app;
    if (app.initialize() != 0) {
        Logger::error("Failed to initialize application");
        return -1;
    }
    app.run();
    app.shutdown();
    return 0;
}