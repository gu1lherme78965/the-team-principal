#pragma once

#include <SDL3/SDL.h>

#include "logger.hpp"

class Window {
public:
    Window();
    ~Window();

    // lifehooks
    int initialize();
    void shutdown();

private:
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
};