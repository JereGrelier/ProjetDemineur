#ifndef GRID_H
#define GRID_H
#include <stdlib.h>
#include <stdbool.h>
typedef struct sommet sommet;


/**
 * @brief The cell structure
 * 
 */
struct sommet
{
    int nbMineAround;
    bool mined;
    int state; // 1 if discovered, 2 if flagged, 0 else
};

/**
 * @brief Create a Grid
 * 
 * @param h Height
 * @param w Width
 * @return the grid 
 */
void CreateGrid(int h, int w);

/**
 * @brief Verify the surrondings of a cell
 * 
 * @param mySommet The cell selected
 * @param myGrid The grid
 */
void getSurrond(sommet *mySommet);

/**
 * @brief Display the grid
 * 
 * 
 */
void DisplayGrid();

/**
 * @brief Check whether an input is an integer or not
 * 
 * @return The integer 
 */
int checkInt();

#endif