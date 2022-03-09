/**
 * @file grid.c
 * @author Jeremy Grelier (jeremy.grelier@enseirb-matmeca.fr)
 * @brief The source file for the grid and cells
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include "../include/grid.h"
#include <stdio.h>
#include <time.h>

grid *CreateGrid(int h, int w) {

    grid *myGrid = malloc(sizeof(*myGrid));
    sommet *firstSommet = malloc(sizeof(*firstSommet));

    if (myGrid == NULL || firstSommet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    firstSommet->voisinage = 0;
    srand(time(NULL));
    sommet *actualSommet = firstSommet;
    firstSommet->next = actualSommet;
    for (int i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            actualSommet->voisinage = rand() % 4;
            actualSommet->next = malloc(sizeof(*actualSommet));
            actualSommet = actualSommet->next;
        }
    }
    myGrid->firstSommet = firstSommet;
    myGrid->h = h;
    myGrid->w = w;
    return myGrid;
}

void DisplayGrid(grid *myGrid) {
    if (myGrid == NULL)
    {
        exit(EXIT_FAILURE);
    }

    sommet *actuel = myGrid->firstSommet;
    for (int a = 0; a < myGrid->w; a++)
    {
        printf("____");
    }
    printf("\n");
    for (int i = 0; i < myGrid->w; i++)
    {
        printf("|");
        for (int j = 0; j < myGrid->w; j++)
        {
            printf("_");
            printf("%d_|", actuel->voisinage);
        }
        printf("\n");
    }
}

void main() {
        grid *myGrid = CreateGrid(10,5);
        DisplayGrid(myGrid);
}