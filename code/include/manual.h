#ifndef MANUAL_H
#define MANUAL_H
#include <stdlib.h>
#include <stdio.h>
#include "grid.h"


/**
 * @brief Reveal a cell
 * 
 * @param mySommet The cell to reveal
 */
void * Reveal(int h, int w, grid* myGrid);

/**
 * @brief Temp Fuction to loose ==> Move to end
 * 
 * @param myGrid the grid
 */
void handleLoose(grid *myGrid);


/**
 * @brief Temp Fuction to Win ==> Move to end
 * 
 * @param myGrid the grid
 */
void handleWin(grid *myGrid);

/**
 * @brief Check if the grid has been fully discovered
 * 
 * @param myGrid The grid
 */
void checkWin(grid *myGrid);

/**
 * @brief The function to start flagging a cell
 * 
 * @param myGrid The grid
 */
void flagCell(grid * myGrid);

/**
 * @brief The function to reveal a cell
 * 
 * @param h The line of the cell
 * @param w The column of the cell
 * @param myGrid The grid
 */
void * Reveal(int h, int w, grid* myGrid);

#endif