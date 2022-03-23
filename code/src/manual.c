
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
int height;
int width;
sommet grid[height][width];

void Reveal(int h, int w) {
    printf("Revealing the cell at %d ; %d\n", h, w);
    sommet *mySommet = grid[h][w];        
    if (mySommet->mined)
    {
        handleLoose();
    }
    mySommet->state = 1;
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
    flagCell();
}

void handleFlag(int h, int w){
    sommet *MySommet = grid[h][w];
    if(MySommet->state != 2)
        MySommet->state = 2;
}

void PrintWin() {
    system("clear");
    DisplayGrid();
    printf("You Win\n");
    system("paplay ../assets/GG.wav &");
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sommet *MySommet = grid[i][j];
            MySommet->state = 1;
        }
        
    }
    return;
}

void checkWin() {
    PrintWin();
}