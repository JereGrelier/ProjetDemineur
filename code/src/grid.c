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


//TODO Complete function
void *getSurrond(sommet *mySommet, grid *myGrid) {
    int res = 0;
    mySommet->voisinage = res;
}

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
            actualSommet->coor[0] = i;
            actualSommet->coor[1] = j;
            actualSommet->mined = rand() % 2;
            actualSommet->flagged = rand() % 2;
            actualSommet->discovered = rand() % 2;
            actualSommet->voisinage = rand() % 10;
            //getSurrond(actualSommet, myGrid);
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
    for (int i = 0; i < myGrid->h; i++)
    {
        printf("|");
        for (int j = 0; j < myGrid->w; j++)
        {
            if (actuel->discovered == 0)
            {
                printf("?|");
            }
            else if (actuel->flagged == 1)
            {
                printf("F|");
            }
            else if (actuel->mined == VRAI) {
                printf("*|");
            }
            else {
                printf("%d|", actuel->voisinage);
            }
            if(actuel->next != NULL)
                actuel = actuel->next;
        }
        printf("\n");
    }
}

void * Reveal(int h, int w, grid* myGrid) {
    printf("Revealing the cell at %d ; %d\n", h, w);
    sommet * actual = myGrid->firstSommet;
    while (actual->next != NULL) {
        if (actual->coor[0] == h && actual->coor[1] == w)
            break;
        actual = actual->next;
    } 
    
    if (actual->mined == VRAI)
    {
        handleLoose(myGrid);
    }
    actual->flagged = FAUX;
    actual->discovered = VRAI;
    DisplayGrid(myGrid);
}

//TMP : To remove and set in end...
void handleLoose(grid *myGrid) {
    printf("You lost\n");
    sommet * actual = myGrid->firstSommet;
    while (actual->next != NULL) {
        actual->discovered = VRAI;
        actual->flagged = FAUX;
        actual = actual->next;
    }
    printf("Here is the full grid\n");
    DisplayGrid(myGrid);
    _Exit(0);
}

int main() {
        grid *myGrid = CreateGrid(5,5);
        DisplayGrid(myGrid);
        Reveal(3,2, myGrid);
        return 0;
}