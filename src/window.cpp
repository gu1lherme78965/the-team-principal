#include "window.hpp"

Window::Window() {
    Logger::info("Window created");
}

Window::~Window() {
    Logger::info("Window destroyed");
}

int Window::initialize() {
    Logger::info("Initializing window");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        Logger::error("SDL Init failed: " + std::string(SDL_GetError()));
        return SDL_APP_FAILURE;
    }   
    if (!SDL_CreateWindowAndRenderer("The Team Principal", 800, 600, SDL_WINDOW_RESIZABLE, &_window, &_renderer)) {
        Logger::error("Failed to create window and renderer: " + std::string(SDL_GetError()));
        return SDL_APP_FAILURE;
    }
    if (!_window || !_renderer) {
        Logger::error("Failed to create window or renderer: " + std::string(SDL_GetError()));
        return SDL_APP_FAILURE;
    }
    return 0;
}

void Window::shutdown() {
    Logger::info("Shutting down window");
    if (_renderer) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
    }
    if (_window) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }
}