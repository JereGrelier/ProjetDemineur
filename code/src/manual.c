
/**
 * @file manual.c
 * @author jeremy.grelier@enseirb-matmeca.fr
 * @brief The code for a manual game
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/manual.h"

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

void handleWin(grid *myGrid) {
    sommet *currentSommet = myGrid->firstSommet; 
    while (currentSommet->next != NULL) {
        if (currentSommet->discovered == FAUX)
            currentSommet->flagged =VRAI;
        currentSommet = currentSommet->next;
    }
    system("clear");
    DisplayGrid(myGrid);
    printf("You Win\n");
    system("paplay ../assets/GG.wav &");
    _Exit(0);
}

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
    handleWin(myGrid);
    
}