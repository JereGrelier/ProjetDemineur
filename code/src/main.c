#include "../include/manual.h"

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
        DisplayGrid(myGrid);
        flagCell(myGrid);
        printf("x? ==>"); 
        x = checkInt();
        printf("\ny? ==>");
        y = checkInt();
        Reveal(x,y, myGrid);
        checkWin(myGrid);
    }
}