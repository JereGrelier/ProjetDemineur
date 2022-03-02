#include "../include/grid.h"

void * CreateGrid(int w, int h) {
    int grid[w][h];
    return grid
}

void DisplayGrid(int **grid, int w, int h) {
    for (size_t i = 0; i < h; i++)
    {
        printf(|);
        for (size_t j = 0; j < w; i++)
        {
            printf(%d,grid[j][i])
        }
        
    }
    
}