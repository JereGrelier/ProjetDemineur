#include "../include/manual.h"
#include "../include/menu.h"

int height;
int width;
int nbMines;

int main() {
    system("clear");
    /* printf("SIZE OF THE GRID : \n");
    printf("x? ==>"); 
    height = checkInt();
    printf("y? ==>");
    width = checkInt();
    printf("How many mines? ==>");
    nbMines = checkInt(); */
    CreateGrid(height, width, nbMines);
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
    return 0;
}