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
#include "../include/grid.h"
#include <stdio.h>
#include <time.h>

//TODO Complete function
void *getSurrond(sommet *mySommet, grid *myGrid) {
    sommet *currentSommet = myGrid->firstSommet;
    //DEBUG VAR
    int a = mySommet->coor[0];
    int b = mySommet->coor[1];
    int c = currentSommet->coor[0];
    int d = currentSommet->coor[1];
    //FIN DEBUG VAR
    while (currentSommet->next != NULL)
    {
        if ((currentSommet->next == mySommet || mySommet->next==currentSommet) && currentSommet->coor[0] == mySommet->coor[0])
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
            if (actuel->flagged == VRAI)
            {
                printf("\033[1;38;5;46m");
                printf("F");
                printf("\033[0m|");
            }
            else if (actuel->discovered == FAUX)
            {
                printf("?|");
            }
            
            else if (actuel->mined == VRAI) {
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

void checkWin(grid *myGrid) {
    sommet *currentSommet = myGrid->firstSommet;
    while (currentSommet->next != NULL)
    {
        if(currentSommet->discovered == FAUX && currentSommet->mined == VRAI){
            currentSommet = currentSommet->next;
            continue;
        }
        if(currentSommet->discovered == FAUX && currentSommet->mined == FAUX){
            return;
        }
        currentSommet = currentSommet->next;
    }
    printf("You Win\n");
    _Exit(0);
    
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

void flagCell(grid * myGrid) {
    printf("Do you want to flag a cell\n1. No\n2. Yes\n==> ");
    int a = checkInt();
    switch (a) {
        case 1:
            return;
        case 2: {
            printf("Flagging...\n");
            printf("x? ==>"); 
            int x = checkInt();
            printf("\ny? ==>");
            int y = checkInt();
            sommet * actual = myGrid->firstSommet;
            while (actual->next != NULL) {
                if (actual->coor[0] == x && actual->coor[1] == y)
                    break;
                actual = actual->next;
            } 
            actual->flagged = VRAI;
            DisplayGrid(myGrid);
            break;
        }
        default:
            break;
    }
    flagCell(myGrid);
}

void main() {
    int h, w = 0;
    char tmp;
    printf("SIZE OF THE GRID : \n");
    printf("x? ==>"); 
    h = checkInt();
    printf("y? ==>");
    w = checkInt();
    grid *myGrid = CreateGrid(h,w);
    DisplayGrid(myGrid);
    int x, y;
    sommet *currentSommet = myGrid->firstSommet;
    while (VRAI)
    {
        system("clear");
        char c = getchar();
        if(c == 'f')
            flagCell(myGrid);
        DisplayGrid(myGrid);
        printf("x? ==>"); 
        x = checkInt();
        printf("\ny? ==>");
        y = checkInt();
        Reveal(x,y, myGrid);
        checkWin(myGrid);
    }
}
