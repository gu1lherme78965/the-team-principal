#include "application.hpp"

#include <iostream>

Application::Application() {
    std::cout << "Application created" << std::endl;
}

Application::~Application() {
    std::cout << "Application destroyed" << std::endl;
}

int Application::initialize() {
    std::cout << "Initializing The Team Principal " << _version << std::endl;
    _running = true;
    return 0;
}

void Application::shutdown() {
    std::cout << "Shutting down The Team Principal " << _version << std::endl;
    _running = false;
    return;
}

void Application::run() {
    std::cout << "Running The Team Principal " << _version << std::endl;
    while (_running) {
        // main loop
    }
    return;
}