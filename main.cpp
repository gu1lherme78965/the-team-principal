#include "application.hpp"
#include "logger.hpp"

int main(int argc, char* argv[]) {
    Logger::initialize();
    Application app;
    if (!app.initialize()) {
        return 1;
    }
    
    app.run();
    app.shutdown();

    return 0;
}