#pragma once

#include "Vector2.h"
#include <SDL2/SDL.h>

class rectangle
{
private:
    Color color;
    Vector2 pos, scale;
    SDL_Rect rect;

    int value;
public: 
    rectangle();
    rectangle(const int S_HEIGHT, const int S_WIDTH, int value, int amountOfRectangles, int place);
    ~rectangle();

    void draw(SDL_Renderer* renderer);
};