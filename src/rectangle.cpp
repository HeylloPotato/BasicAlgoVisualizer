#include "rectangle.h"

rectangle::rectangle() {}

rectangle::rectangle(const int S_HEIGHT, const int S_WIDTH, int value, int amountOfRectangles, int place)
{
    this->value = value;

    this->width = S_WIDTH / amountOfRectangles;
    rect.x = width * place; // position X
    rect.y = S_HEIGHT - value; // position Y
    rect.w = width; // width
    rect.h = value; // height

    this->color.r = 255;
    this->color.g = 255;
    this->color.b = 255;
    this->color.o = 255;
}

rectangle::~rectangle() {}

void rectangle::resetPosition(int place)
{
    rect.x = this->width * place; // position X
}

void rectangle::draw(SDL_Renderer* renderer)
{
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