#include "application.hpp"
#include "logger.hpp"

#include <iostream>

Application::Application() {
    Logger::info("Application created");
}

Application::~Application() {
    Logger::info("Application destroyed");
}

int Application::initialize() {
    Logger::info("Initializing The Team Principal " + _version);
    _running = true;
    return 0;
}

void Application::shutdown() {
    Logger::info("Shutting down The Team Principal " + _version);
    _running = false;
    return;
}

void Application::run() {
    Logger::info("Running The Team Principal " + _version);
    while (_running) {
        // main loop
    }
    return;
}