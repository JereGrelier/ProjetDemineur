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
#include "../include/menu.h"

//Global Variables
int height;
int width;
sommet grid[height][width];


//TODO Complete function
void getSurrond(sommet *mySommet) {
    if (mySommet->mined)
        return;
}

void CreateGrid(int h, int w) {
    sommet *MySommet;
    srand(time(NULL));
    for (int i = 1; i <= h; i++)
    {
        for (size_t j = 1; j <= w; j++)
        {
            MySommet->mined = rand() % 2;
            MySommet->state = 0;
            grid[i][j] = MySommet;
        }
    }
    return;
}

void DisplayGrid() {
    if (grid == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("    y -->\n");
    
    for (int i = 0; i < height; i++)
    {
        printf("x=%d |", i+1);
        for (int j = 0; j < width; j++)
        {
            sommet mySommet = grid[i][j]; 
            if (mySommet.state == 2)
            {
                printf("\033[1;38;5;46m");
                printf("F");
                printf("\033[0m|");
            }
            else if (!mySommet.state)
            {
                printf("?|");
            }
            
            else if (mySommet.mined) {
                printf("\033[1;31m");
                printf("*");
                printf("\033[0m|");
            }
            else {
                printf("%d|", mySommet.nbMineAround);
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
