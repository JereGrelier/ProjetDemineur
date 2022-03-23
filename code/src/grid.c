/**
 * @file grid.c
 * @author Jeremy Grelier (jeremy.grelier@enseirb-matmeca.fr)
 * @brief The source file for the grid and cells
 * @version 0.5
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/grid.h"


//TODO Complete function
void getSurrond(sommet *mySommet, grid *myGrid) {
    if (mySommet->mined)
        return;
    sommet *currentSommet = myGrid->firstSommet;
    int a = mySommet->coor[0];
    int b = mySommet->coor[1];
    int c = currentSommet->coor[0];
    int d = currentSommet->coor[1];
    while (currentSommet->next != NULL)
    {
        if ((currentSommet->next == mySommet || mySommet->next==currentSommet) && c == a
        || (c - 1 == a || c + 1 == a) && d == b
        || (a==c-1 && b==d-1 || a==c+1 && b==d+1 || a==c-1 && b==d+1 || a==c+1 && b==d-1))
        {
            if(currentSommet->mined == VRAI)
                mySommet->voisinage+=1;
        }
        currentSommet = currentSommet->next;
        c = currentSommet->coor[0];
        d = currentSommet->coor[1];
    }
}

grid *CreateGrid(int h, int w) {

    grid *myGrid = malloc(sizeof(*myGrid));
    sommet *firstSommet = malloc(sizeof(*firstSommet));

    if (myGrid == NULL || firstSommet == NULL)
    {
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    sommet *actualSommet = firstSommet;
    firstSommet->next = actualSommet;
    for (int i = 1; i <= h; i++)
    {
        for (size_t j = 1; j <= w; j++)
        {
            actualSommet->coor[0] = i;
            actualSommet->coor[1] = j;
            actualSommet->mined = rand() % 2;
            actualSommet->flagged = FAUX;
            actualSommet->discovered = FAUX;
            actualSommet->next = malloc(sizeof(*actualSommet));
            actualSommet = actualSommet->next;
        }
    }
    myGrid->firstSommet = firstSommet;
    myGrid->h = h;
    myGrid->w = w;
    actualSommet = firstSommet;
    while (actualSommet->next != NULL) {
        getSurrond(actualSommet, myGrid);
        actualSommet = actualSommet->next;
    }
    return myGrid;
}

void DisplayGrid(grid *myGrid) {
    if (myGrid == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("    y -->\n");
    sommet *actuel = myGrid->firstSommet;
    for (int i = 0; i < myGrid->h; i++)
    {
        printf("x=%d |", i+1);
        for (int j = 0; j < myGrid->w; j++)
        {
            if (actuel->flagged)
            {
                printf("\033[1;38;5;46m");
                printf("F");
                printf("\033[0m|");
            }
            else if (!actuel->discovered)
            {
                printf("?|");
            }
            
            else if (actuel->mined) {
                printf("\033[1;31m");
                printf("*");
                printf("\033[0m|");
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



int checkInt() {
    char tmp;
    int res = 0;
    
    while(res == 0) {
        scanf("%s", &tmp);
        res = atoi(&tmp);
        if(res == 0)
            printf("Not a valid number, please retry\n==>");
    }
    return res;
}
