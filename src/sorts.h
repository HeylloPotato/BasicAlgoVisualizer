#pragma once

/* 
everything that involves sorting,
including all the algorithms neatly packed together 
*/

#include <SDL2/SDL.h>

namespace sorts {
    int addSortSpeed(int curSpeed);
    int removeSortSpeed(int curSpeed);
    void swap(SDL_Renderer* renderer, std::vector<rectangle> &rects, int first, int second, int sortTime);
    void sortingDraw(SDL_Renderer* renderer, std::vector<rectangle> rects);

    //sorts
    void bubbleSort(SDL_Renderer* renderer, std::vector<rectangle> &rects, int sortTime);
    void selectionSort(SDL_Renderer* renderer, std::vector<rectangle> &rects, int sortTime); 
}