#include <iostream>
#include "program.h"
#include "sorts.h"

using namespace sorts;

program::program()
    : SCREEN_WIDTH(0), SCREEN_HEIGHT(0)
{}

// Construct the program and then immediately assign SCREEN_WIDTH/HEIGHT
program::program(Vector2 ss)
    : SCREEN_WIDTH(ss.x), SCREEN_HEIGHT(ss.y)
{
    // initialize SDLl, then check if it intialized
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "SDL could not initialize, SDL_ERROR: %s\n", SDL_GetError();
    }

    // Create a window, with the scree height and width variables
    this->window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // Create a renderer from the window
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    // Check to see if either the window and or renderer couldn't be created
    if (window == nullptr || renderer == nullptr)
    {
        std::cout << "Window and/or renderer could not be created, SDL_ERROR: %s\n", SDL_GetError();
    }
    // Initialize all the starting rectangles
    this->createRectangle(20);

    //Get the program actually running; after initiliazing everything
    this->mainLoop();
}

program::~program() {}

void program::mainLoop()
{
    // While the program is running, this loop will run
    bool running = true;
    while(running)
    {
        while (SDL_PollEvent(&event))
        {
            // check to see if a key is down
            if (event.type == SDL_KEYDOWN && !sorting)
            {
                // Check for keyboard; and what key
                switch (event.key.keysym.sym)
                {
                    // add x amt of rectangles when right arrow is pressed
                    case SDLK_RIGHT:
                        addRectangles(5);
                        break;
                    // remove x amt of rectangles when left arrow is pressed
                    case SDLK_LEFT:
                        removeRectangles(5);
                        break;
                    // add or remove sort speed; up arrow for faster; down for slower
                    case SDLK_UP:
                        sortSpeed = sorts::addSortSpeed(sortSpeed);
                        break;
                    case SDLK_DOWN:
                        sortSpeed = sorts::removeSortSpeed(sortSpeed);
                        break;
                    // reset rectangles
                    case SDLK_SPACE:
                        createRectangle(rectangles.size());
                        break;
                    // Number on keyboard determines what sort
                    case SDLK_1:
                        sorts::bubbleSort(this->renderer, this->rectangles, this->sortSpeed);
                        break;
                }                    
            }

            // stop the loop if the program is quit out of 
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // Draw everything to the backbuffer
        this->draw();
        // Swap the back buffer and the front buffer; Rendering the scene
        SDL_RenderPresent(this->renderer);
    }

    // Cleanup and destroy everything
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void program::draw()
{
    // Change the background color to black, then put on back buffer
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);

    for (uint8_t i = 0; i < this->rectangles.size(); i++)
    {
        // for every iteration of the loop draw each rectangle
        rectangles[i].draw(this->renderer);
    }
}

void program::createRectangle(int amt)
{
    // clear rectangles to make sure there are none
    this->rectangles.clear();

    // Loop through how many rectangles there will be
    for (uint8_t i = 0; i < amt; i++)
    {
        // every time it loops through create a temp rectangle
        // Set the value of rectangle between 100-400
        // put it in ith place
        rectangle temp(SCREEN_HEIGHT, SCREEN_WIDTH, rand() % 400 + 100, amt, i);
        // take the temp rectangle and put it in the rectangles array
        rectangles.push_back(temp);
    }
}

void program::addRectangles(int amt)
{
    int tempAmt = rectangles.size();

    // While tempAmt is lower than 200
    // Keep adding amt to it
    // until it is divisible by screen_width
    while (tempAmt < 200){
        tempAmt += amt;
        if (this->SCREEN_WIDTH % tempAmt == 0)
        {
            break;
        }
    }

    std::cout << tempAmt << std::endl;

    // Clear the array; Create all the rectangles 
    this->createRectangle(tempAmt);
}

void program::removeRectangles(int amt)
{
    int tempAmt = rectangles.size();

    // While tempAmt is higher than 10
    // Keep subtracting amt to it
    // until it is divisible by screen_width
    while (tempAmt > 10){
        tempAmt -= amt;
        if (this->SCREEN_WIDTH % tempAmt == 0)
        {
            break;
        }
    }

    std::cout << tempAmt << std::endl;

    // Clear the array; Create all the rectangles 
    this->createRectangle(tempAmt);
}

int main(int argv, char** args)
{  
    // Create a program object, with the screen size (width, height)
    program Program(Vector2(800, 600));
    return 0;
}