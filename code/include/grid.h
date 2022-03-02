#ifndef GRID_H
#define GRID_H
#include <stdlib.h>
#define VRAI 1
#define FAUX 0
typedef int BOOLEAN;


/**
 * @brief The cell structure
 * 
 */
struct sommet
{
    BOOLEAN marked;
    BOOLEAN flagged;
    BOOLEAN discovered;
};

/**
 * @brief Create a Grid
 * 
 * @param h Height
 * @param w Width
 * @return the grid 
 */
struct sommet **CreateGrid(int h, int w);

/**
 * @brief Display the grid
 * 
 * @param h Height
 * @param w width
 * @param grid the grid
 */
void DisplayGrid(struct sommet **grid, int h, int w);

/**
 * @brief Delete the grid
 * 
 * @param grid the grid to delete
 */
void DeleteGrid(struct sommet **grid);



#endif