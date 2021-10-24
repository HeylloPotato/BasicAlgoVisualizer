#include "rectangle.h"

rectangle::rectangle() {}

rectangle::rectangle(const int S_HEIGHT, const int S_WIDTH, int value, int amountOfRectangles, int place)
{
    int width = S_WIDTH / amountOfRectangles;
    rect.x = 0 + width * place; // position X
    rect.y = S_HEIGHT - value; // position Y
    rect.w = width; // width
    rect.h = value; // height

    this->color.r = 255;
    this->color.g = 255;
    this->color.b = 255;
    this->color.o = 255;
}

rectangle::~rectangle() {}

void rectangle::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.o);
    SDL_RenderFillRect(renderer, &rect);
}