#pragma once

#include <SDL2/SDL.h>
#include "utils.h"

class rectangle
{
private:
    // Color of the rectangle
    Color color;

    // Position (x, y) of rectangle
    // Scale (x, y) of rectangle
    Vector2 pos, scale;

    // Rectangle of the rectangle object
    SDL_Rect rect;
    // Used for start and end position of the object, when swapping positions
    SDL_Rect tempRectS, tempRectE;
    
    // Width of the rectangle object; used for calculations
    int width;
    // Value of the object
    // Used for comparing the objects during the sorts 
    int value;
public: 
    rectangle();

    // constructor to set up the rectangle
    rectangle(const int S_HEIGHT, const int S_WIDTH, int value, int amountOfRectangles, int place);
    ~rectangle();

    // put the rectangle onto the back buffer
    // along with the color and size of it
    void draw(SDL_Renderer* renderer);

    // set the position of the rectangle
    void setPosition(int place);
    // set the color of the rectangle
    // used to see what rectangles are getting compared during sort
    void setColor(Color col);

    // return the value of the object for comparing during sort
    int getValue();
    // return the width of the object for calculation what position it needs to be at
    int getWidth();
};