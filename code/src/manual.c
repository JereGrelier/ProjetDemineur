
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

//Global variables
Grid *grid;

void Reveal(int h, int w) {
    printf("Revealing the cell at %d ; %d\n", h, w);
    h--;
    w--;
    if (grid->sommet[h][w].mined)
    {
        handleLoose();
    }
    grid->sommet[h][w].state = 1;
    DisplayGrid();
}

//TODO : MVC
void flagCell() {
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
            handleFlag(x,y);
            DisplayGrid();
            break;
        }
        default:
            break;
    }
    flagCell(grid);
}

void handleFlag(int h, int w){
    h--;
    w--;
    if(grid->sommet[h][w].state != 2)
        grid->sommet[h][w].state = 2;
}

void PrintWin() {
    system("clear");
    RevealAll();
    DisplayGrid();
    printf("You Win\n");
    system("paplay ./assets/GG.wav &");
    _Exit(0);
}

void handleLoose() {
    printf("You lost\n");
    RevealAll();
    printf("Here is the full grid\n");
    DisplayGrid();
    _Exit(0);
}

void RevealAll(){
    for (int i = 0; i < grid->height; i++)
    {
        for (int j = 0; j < grid->width; j++)
        {
            grid->sommet[i][j].state = 1;
        }
        
    }
    return;
}

void checkWin() {
    PrintWin();
}