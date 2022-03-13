#ifndef GRID_H
#define GRID_H
#include <stdlib.h>
#define VRAI 1
#define FAUX 0
typedef int BOOLEAN;
typedef struct sommet sommet;
typedef struct grid grid;


/**
 * @brief The cell structure
 * 
 */
struct sommet
{
    int voisinage;
    BOOLEAN mined;
    BOOLEAN flagged;
    BOOLEAN discovered;
    int coor[2];
    struct sommet *next;
};

/**
 * @brief The grid structure
 * @param w Width
 * @param h Height
 */
struct grid
{
    int w;
    int h;
    struct sommet *firstSommet;
};


/**
 * @brief Create a Grid
 * 
 * @param h Height
 * @param w Width
 * @return the grid 
 */
grid *CreateGrid(int h, int w);

/**
 * @brief Verify the surrondings of a cell
 * 
 * @param mySommet The cell selected
 * @param myGrid The grid
 * @return How much mines are around the cell passed in parameter
 */
void *getSurrond(sommet *mySommet, grid *myGrid);

/**
 * @brief Display the grid
 * 
 * @param grid the grid
 */
void DisplayGrid(grid *grid);

/**
 * @brief Delete the grid
 * 
 * @param grid the grid to delete
 */
void DeleteGrid(struct sommet **grid);

/**
 * @brief Reveal a cell
 * 
 * @param mySommet The cell to reveal
 */
void * Reveal(int h, int w, grid* myGrid);

/**
 * @brief Temp Fuction to test reveal
 * 
 * @param myGrid the grid
 */
void handleLoose(grid *myGrid);

#endif