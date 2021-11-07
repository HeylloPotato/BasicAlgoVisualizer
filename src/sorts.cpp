// #include "sorts.h"
// #include <iostream>
// #include <algorithm>

// enum Sorts{
//     bubble,
//     quick
// };

// struct sorts::lessThan
// {
//     inline bool operator() (rectangle& rect1, rectangle& rect2)
//     {
//         return (rect1.getValue() < rect2.getValue());
//     }
// };

// void sorts::sortRectangles(std::vector<rectangle> &Rects) {}

// void sorts::bubbleSort(std::vector<rectangle> &Rects)
// {
//     for (int j = 0; j < Rects.size() - 1; j++)
//     {
//         bool swapped = false;

//         for (int i = 0; i < Rects.size() - 1; i++)
//         {
//             if (Rects[i].getValue() > Rects[i + 1].getValue())
//             {
//                 this->swap(Rects, i);
//                 swapped = true;
//             }
//         }

//         if (!swapped)
//         {
//             break;
//         }
//     }
// }

// void sorts::swap(std::vector<rectangle> &Rects, int index)
// {
//     Uint32 time = SDL_GetTicks();
//     Uint32 sTime = time;
//     int dTime = 500;

//     rectangle tempRect = Rects[index];
//     Rects[index] = Rects[index+1];
//     Rects[index+1] = tempRect;
//     Rects[index].setColor(Color(255, 0, 0, 255));
//     Rects[index+1].setColor(Color(255, 0, 0, 255));

//     Rects[index].resetPosition(index);
//     Rects[index+1].resetPosition(index+1);

//     std::cout << sTime + dTime;
//     while (time < sTime + dTime)
//     {
//         time = SDL_GetTicks();
//     }
// }