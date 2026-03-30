#pragma once

#include <string>
#include <SDL3/SDL.h>

#include "window.hpp"
#include "input.hpp"

class Application {
public:
    Application();
    ~Application();

    // lifehooks
    int initialize();
    void shutdown();

    void run();

private:
    std::string _version = "0.0.1";
    bool _running = false;

    Window _window;
    Input _input;
};