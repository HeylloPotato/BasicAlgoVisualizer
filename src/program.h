#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "utils.h"
#include "rectangle.h"

class program
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    const int SCREEN_WIDTH, SCREEN_HEIGHT;

    // Array of all the rectangles
    std::vector<rectangle> rectangles;

    // check if sorting or not
    bool sorting;
public:
    program();
    // Construct the program object with the screen size
    program(Vector2 ss);
    ~program();

    // The main running loop of the program; Basically the heart
    void mainLoop();

    // Set the back buffer
    void draw();

    // Create triangles
    void createRectangle(int amt);
    // Add rectangles to the array of rectangles
    void addRectangles(int amt);
    // Remove some amount of rectangles
    void removeRectangles(int amt);

    int sortSpeed = 10; 
};