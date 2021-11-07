#pragma once

#include "Vector2.h"
#include <SDL2/SDL.h>

class rectangle
{
private:
    Color color;
    Vector2 pos, scale;
    SDL_Rect rect;
    SDL_Rect tempRectS, tempRectE;
    
    int width;
    int value;
public: 
    rectangle();
    rectangle(const int S_HEIGHT, const int S_WIDTH, int value, int amountOfRectangles, int place);
    ~rectangle();

    void draw(SDL_Renderer* renderer);
    void resetPosition(int place);
    int getValue();
    void setColor(Color col);
    int getWidth();
    void animate(float f);
};