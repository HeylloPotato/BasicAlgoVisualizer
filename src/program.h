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


    const int SCREEN_WIDTH, SCREEN_HEIGHT;
    int rectangleSize = 10;
public:
    program();
    program(const char* title, Vector2 size);
    ~program();

    int running();
    void createRectangles();
    void draw();
    std::vector<rectangle> Rectangles;

    struct lessThan;
    void sortRectangles(std::vector<rectangle> &Rects);
    void bubbleSort(std::vector<rectangle> &Rects);
    void swap(std::vector<rectangle> &Rects, int index);
};