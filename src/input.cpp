#include "input.hpp"

void Input::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_KEY_DOWN) {
            keyDown[event.key.key] = true;
        } else if (event.type == SDL_EVENT_KEY_UP) {
            keyDown[event.key.key] = false;
        }
    }
}

bool Input::isKeyDown(SDL_Keycode key) {
    return keyDown[key];
}