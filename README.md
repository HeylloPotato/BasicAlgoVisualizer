# Simple Sorting Visualizer

## Controls
- 1 - Bubble Sort
- 2 - Selection Sort
- Space - Randomize Array
- Left Arrow - Make amount of rectangles smaller by 5
- Right Arrow - Make amount of rectangles larger by 5
- Up Arrow - Make the rate of sorting slower by 10
- Down Arrow - Make the rate of sorting faster by 10

## Sorts
- Bubble
- Selection

## Compile
Compiled with a Makefile with this:  																																					    
```g++ src/*.cpp -Idependencies/include -Wall -Ldependencies/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main```
