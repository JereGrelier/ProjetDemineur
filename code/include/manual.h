#ifndef MANUAL_H
#define MANUAL_H
#include <stdlib.h>
#include <stdio.h>
#include "grid.h"


/**
 * @brief Reveal a cell
 * 
 * @param h The line of the cell
 * @param w The column of the cell
 */
void Reveal(int h, int w);

/**
 * @brief Temp Fuction to loose ==> Move to end
 * 
 */
void handleLoose();


/**
 * @brief Temp Fuction to Win ==> Move to end
 * 
 */
void handleWin();

/**
 * @brief Check if the grid has been fully discovered
 * 
 */
void checkWin();

/**
 * @brief The function to start flagging a cell
 * 
 */
void flagCell();

/**
 * @brief The function which flag a cell
 * 
 * @param h The line of the cell
 * @param w The column of the cell
 */
void handleFlag(int h, int w);

/**
 * @brief The function to reveal a cell
 * 
 * @param h The line of the cell
 * @param w The column of the cell
 * @param myGrid The grid
 */
void Reveal(int h, int w);

void RevealAll();
#endif