# Simple Sorting Visualizer
This is a sorting visualizer which you control via keys on a keyboard

# To do list
General additions: <br/>
- ImGUI Version

Sorts: <br/>	
- Quicksort <br/>
- Mergesort <br/>	
- Heapsort <br/>			
- Bucket sort <br/>	
    
## Controls
#### Sort Controls
- 1 - Bubble Sort
- 2 - Selection Sort
- 3 - Insertion sort

#### Array/Rectangle Controls
- Space - Randomize array
- Left Arrow - Make amount of rectangles smaller by 5
- Right Arrow - Make amount of rectangles larger by 5
- Up Arrow - Make the rate of sorting slower by 10
- Down Arrow - Make the rate of sorting faster by 10

## Compile
Compiled with a Makefile with this:  																																					    
```g++ src/*.cpp -Idependencies/include -Wall -Ldependencies/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main```
