#include "../include/manual.h"

int height;
int width;
int nbMines;

int main() {
    system("clear");
    printf("SIZE OF THE GRID : \n");
    printf("x? ==>"); 
    height = checkInt();
    printf("y? ==>");
    width = checkInt();
    printf("How many mines? ==>");
    nbMines = checkInt();
    CreateGrid(height, width, nbMines);
    int x, y;
    while (true)
    {
        system("clear");
        DisplayGrid();
        flagCell();
        printf("x? ==>"); 
        x = checkInt();
        printf("\ny? ==>");
        y = checkInt();
        if(isInGrid(x,y))
            Reveal(x,y);
        else
            continue;
        checkWin();
    }
    return 0;
}