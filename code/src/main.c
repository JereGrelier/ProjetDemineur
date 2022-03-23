#include "../include/manual.h"

int height;
int width;
int nbMines;

int main() {
    printf("SIZE OF THE GRID : \n");
    printf("x? ==>"); 
    height = checkInt();
    printf("y? ==>");
    width = checkInt();
    printf("How many mines? ==>");
    nbMines = checkInt();
    CreateGrid(height, width, nbMines);
    DisplayGrid();
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
        Reveal(x,y);
        checkWin();
    }
    return 0;
}