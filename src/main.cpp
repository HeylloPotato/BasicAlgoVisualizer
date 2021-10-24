#include <SDL2/sdl.h>
#include <iostream>

#include "program.h"
#include "Vector2.h"

program::program()
    : SCREEN_WIDTH(0), SCREEN_HEIGHT(0)
{}

program::program(const char* title, Vector2 size)
    : SCREEN_WIDTH(size.x), SCREEN_HEIGHT(size.y)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL Could not initialize! SDL_Error: %s\n", SDL_GetError();
    }

    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        std::cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError();
    }

    this->renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        std::cout << "Renderer could not be created! SDL_Error: %s\n" << SDL_GetError();
    }

    this->running();
}

program::~program() 
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

int program::running()
{
    this->createRectangles();

    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT){
                return false;
            }
        }
        this->draw();
    }

    return 0;
}

void program::createRectangles()
{
    for (uint8_t i = 0; i < this->rectangleSize; i++)
    {
        rectangle temp(SCREEN_HEIGHT, SCREEN_WIDTH, rand() % 400 + 100, rectangleSize, i);
        Rectangles.push_back(temp);
    }
}

void program::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);

    for (uint16_t i = 0; i < this->Rectangles.size(); i++)
    {
         Rectangles[i].draw(renderer);
    }

    SDL_RenderPresent(this->renderer);
}

int main(int argv, char** args)
{  
    program Program("Visualizer", Vector2(800, 600));
    return 0;
}