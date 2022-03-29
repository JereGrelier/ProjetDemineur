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

//Global Variables

extern Grid *grid;


//TODO Complete function
void getNbSurrondingMines(int h, int w) {
   
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid->sommet[i][j].mined)
                break;
            else
            {
                grid->sommet[i][j].nbMineAround ++;
            }
            
        }
        
    }
    
    
}

void CreateGrid(int h, int w, int nbMines) {
    grid = malloc(sizeof(Grid));
    grid->height = h;
    grid->width = w;
    grid->nbMines = nbMines;
    grid->sommet = (sommet **)malloc(grid->height * sizeof(sommet));
    printf(" H : %d\n W : %d\n NbMines : %d\n", grid->height, grid->width, grid->nbMines);
    int minesToPlace = nbMines;
    for (int i = 0; i < grid->height; i++)
    {
        grid->sommet[i] = (sommet *)malloc(grid->width * sizeof(sommet));
        for (int j = 0; j < grid->width; j++)
        {
            grid->sommet[i][j] = createSommet(&minesToPlace);             
        }
    }
    //placeMines(nbMines);
    getNbSurrondingMines(h,w);
    return;
}

sommet createSommet(int *minesToPlace) {
    bool isMined = false;
    if (minesToPlace) {
        srand(time(NULL));
        printf("mine placed\n");
        isMined = rand() % 2;
        minesToPlace--;
    }
    sommet s = {
            .mined = isMined,
            .state = 0,
            };
    return s;
}

/* void placeMines(int nbMines) {
    srand(time(NULL));
    while (nbMines != 0)
    {
        printf("aaaaaaaaaaaaaaaaaaaaaa\n");
        for (int i = 0; i < grid->height; i++)
        {
            printf("bbbbbbbbbbbbbbbbbbbbbbbbbbb\n");
            for (int j = 0; j < grid->width; j++)
            {
                printf("c\n");
                printf("Mined ? : %d\n", grid->sommet[i][j].mined);
                if (grid->sommet[i][j].mined == false)
                {
                    printf("not mined\n");
                    grid->sommet[i][j].mined = true;
                    nbMines--;
                }
            }
        }
    }
} */

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
