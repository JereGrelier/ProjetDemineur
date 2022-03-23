#include "../include/manual.h"

//Global Variables
int height;
int width;
sommet grid[height][width];

int main() {
    printf("SIZE OF THE GRID : \n");
    printf("x? ==>"); 
    height = checkInt();
    printf("y? ==>");
    width = checkInt();
    CreateGrid(height,width);
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