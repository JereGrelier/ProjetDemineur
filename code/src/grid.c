#include <stdlib.h>
#include "../include/grid.h"
#include <stdio.h>

struct sommet *CreateGrid(struct sommet grid) {
    struct sommet grid[w][h];
    return *grid;
}

void DisplayGrid(struct sommet grid, int w, int h) {
    for (int i = 0; i < h; i++)
    {
        printf("|");
        for (int j = 0; j < w; i++)
        {
            printf("%d |",grid[j][i]);
        }
    }
    
}

void main() {
    struct sommet firstGrid[4][2] = {
        {1,3},
        {3,6},
        {5,9},
        {0,34},
    };
    DisplayGrid(&firstGrid, 4, 2);
}