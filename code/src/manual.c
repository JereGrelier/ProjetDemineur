
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
#include "../include/end.h"
#include "../include/menu.h"


//Global variables
Grid *grid;

void autoRevealWhenNoMinesAround(int h, int w) {
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue; // Skip the cell itself
            if (isInGrid(h + i, w + j))
            {
                sommet *s = &(grid->sommet[h + i][w + j]);
                if (s->state != 1 && !s->mined)
                {
                    AutoReveal(h + i, w + j);
                }
            }
        }
    }
}

void AutoReveal(int h, int w) {
    grid->sommet[h][w].state = 1;
    if (!grid->sommet[h][w].nbMineAround)
    {
        autoRevealWhenNoMinesAround(h,w);
    }
}

void Reveal(int h, int w) {

    if (grid->sommet[h][w].mined)
    {
        handleLoose();
    }
    grid->sommet[h][w].state = 1;
    if (!grid->sommet[h][w].nbMineAround)
    {
        autoRevealWhenNoMinesAround(h,w);
    }
    DisplayGrid();
}

//TODO : MVC
bool flagCell() {
    printf("Do you want to flag a cell\n1. No\n2. Yes\n==> ");
    int a = checkInt(1,2);
    if(a == 2)
        return true;
    return false;
}

void handleFlag(int h, int w){
    if(grid->sommet[h][w].state != 2)
        grid->sommet[h][w].state = 2;
}

void PrintWin() {
    system("clear");
    RevealAll();
    DisplayGrid();
    printf("You Win\n");
    system("cvlc --play-and-exit ./assets/GG.wav 2> /dev/null &");
    handleEndGame();
}

void handleLoose() {
    printf("You lost\n");
    RevealAll();
    printf("Here is the full grid\n");
    system("cvlc --play-and-exit ./assets/loose.wav 2> /dev/null &");
    DisplayGrid();
    handleEndGame();
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

void HideAll(){
    for (int i = 0; i < grid->height; i++)
    {
        for (int j = 0; j < grid->width; j++)
        {
            grid->sommet[i][j].state = 0;
        }
        
    }
    return;
}

void checkWin() {
    int flaggedMines = grid->nbMines;
    for (int i = 0; i < grid->height; i++)
    {
        for (int j = 0; j < grid->width; j++)
        {
            if (!flaggedMines)
            {
                PrintWin();
            }
            if (grid->sommet[i][j].mined && grid->sommet[i][j].state==2)
                flaggedMines--;
        }
    }
    
}

void handleManualGame() {
    int x, y;
    while (true)
    {
        system("clear");
        DisplayGrid();
        bool doFlag = flagCell();
        printf("x? ==>"); 
        x = checkInt(1, grid->height);
        printf("\ny? ==>");
        y = checkInt(1, grid->width);
        if(doFlag){
            if(isInGrid(x-1,y-1))
                handleFlag(x-1,y-1);
            else
                continue;
        }
        else{
            if(isInGrid(x-1,y-1))
                Reveal(x-1,y-1);
            else
                continue;
        }
        checkWin();
    }
}