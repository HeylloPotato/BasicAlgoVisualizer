#include "rectangle.h"

rectangle::rectangle() {}

rectangle::rectangle(const int S_HEIGHT, const int S_WIDTH, int value, int amountOfRectangles, int place)
{
    //set the value of the rectangle
    this->value = value;

    // Make the amount of rectangles be able to be dynamic
    this->width = S_WIDTH / amountOfRectangles;
    rect.x = width * place; // position X
    rect.y = S_HEIGHT - value; // position Y
    rect.w = width; // width
    rect.h = value; // height

    // Make the rectangle white
    this->color = color.white();
}

rectangle::~rectangle() {}

void rectangle::setPosition(int place)
{
    rect.x = this->width * place; // position X
}

void rectangle::draw(SDL_Renderer* renderer)
{
    // set the color of the rectangle, and size
    // Then put it on the back buffer
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.o);
    SDL_RenderFillRect(renderer, &rect);
}

int rectangle::getValue()
{
    return this->value;
}

void rectangle::setColor(Color col)
{
    this->color = col;
}