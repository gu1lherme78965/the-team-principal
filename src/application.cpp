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
    if (_window.initialize() != 0) {
        Logger::error("Failed to initialize window");
        return -1;
    }
    return 0;   
}

void Application::shutdown() {
    _running = false;
    _window.shutdown();
    Logger::info("Shutting down The Team Principal " + _version);
    return;
}

void Application::run() {
    Logger::info("Running The Team Principal " + _version);
    while (_running) {
        SDL_Delay(16); // Simulate ~60 FPS
        _input.update();
        if (_input.isKeyDown(SDLK_ESCAPE)) {
            Logger::info("Escape key pressed, exiting application");
            _running = false;
        }
    }
    return;
}