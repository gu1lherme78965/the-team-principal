#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>

class Input {
private:
    std::unordered_map<SDL_Keycode, bool> keyDown;

public:
    void update();
    bool isKeyDown(SDL_Keycode key);
};