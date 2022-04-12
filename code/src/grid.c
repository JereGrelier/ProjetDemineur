/**
 * @file grid->c
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
#include "../include/menu.h"
#include <unistd.h> // to use sleep for debug

//Global Variables

extern Grid *grid;
int mineToPlace;

void printNInGrid(int h, int w) {
    printf("The case at x=%d and y=%d is not in the grid, please retry\n", h, w);
}

bool isInGrid(int h, int w)
{
    if (
        h < 0 ||
        h >= grid->height ||
        w < 0 ||
        w >= grid->width)
    {
        printNInGrid(h,w);
        sleep(3);
        return false;
    }
    return true;
}

void getNbSurrondingMines(int h, int w)
{
    int nb_mines = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue; // Skip the cell itself
            if (isInGrid(h + i, w + j))
            {
                if (grid->sommet[h + i][w + j].mined)
                {
                    nb_mines++;
                }
            }
        }
    }
    grid->sommet[h][w].nbMineAround = nb_mines;
}

void CreateGrid(int h, int w, int nbMines) {
    srand((time_t)NULL);
    grid = malloc(sizeof(Grid));
    grid->height = h;
    grid->width = w;
    grid->nbMines = nbMines;
    grid->sommet = (sommet **)malloc(grid->height * sizeof(sommet));
    printf(" H : %d\n W : %d\n NbMines : %d\n", grid->height, grid->width, grid->nbMines);
    mineToPlace = nbMines;
    for (int i = 0; i < grid->height; i++)
    {
        grid->sommet[i] = (sommet *)malloc(grid->width * sizeof(sommet));
        for (int j = 0; j < grid->width; j++)
        {
            grid->sommet[i][j] = createSommet(mineToPlace);      
        }
    }
    placeMines(nbMines);
    for (int i = 0; i < grid->height; i++)
    {
        for (int j = 0; j < grid->width; j++)
        {
            getNbSurrondingMines(i, j); 
        }
    }
    return;
}

void placeMines(int nbMines) {
    while (nbMines)
    {
        int h = rand() % grid->height;
        int w = rand() % grid->width;
        if (!grid->sommet[h][w].mined)
        {
            printf("Mines to place : %d\n", nbMines);
            grid->sommet[h][w].mined = true;
            nbMines--;
        }  
    }
}

sommet createSommet() {
    sommet s = {
            .mined = false,
            .state = 0,
            };
    return s;
}

void DisplayGrid() {
    printf("    y -->\n");
    
    for (int i = 0; i < grid->height; i++)
    {
        printf("x=%d |", i+1);
        for (int j = 0; j < grid->width; j++)
        {
            if (grid->sommet[i][j].state == 2)
            {
                printf("\033[1;38;5;46m");
                printf("F");
                printf("\033[0m|");
            }
            else if (!grid->sommet[i][j].state)
            {
                printf("?|");
            }
            
            else if (grid->sommet[i][j].mined) {
                printf("\033[1;31m");
                printf("*");
                printf("\033[0m|");
            }
            else {
                printf("%d|", grid->sommet[i][j].nbMineAround);
            }
        }
        printf("\n");
    }
}


//TODO : MOVE THIS !!!
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
