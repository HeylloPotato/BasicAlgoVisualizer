#pragma once 

#include <vector>

#include <SDL2/SDL.h>
#include "Vector2.h"
#include "rectangle.h"

class program
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    std::vector<rectangle> Rectangles;

    const int SCREEN_WIDTH, SCREEN_HEIGHT;
    int rectangleSize = 3;
public:
    program();
    program(const char* title, Vector2 size);
    ~program();

    int running();
    void createRectangles();
    void draw();
};