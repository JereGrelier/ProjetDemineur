#ifndef GRID_H
#define GRID_H
#include <stdlib.h>
#include <stdbool.h>
typedef struct sommet sommet;
typedef struct grid Grid;

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

struct grid {
    sommet ** sommet;
    int height;
    int width;
    int nbMines;
};
/**
 * @brief Create a Grid
 * 
 * @param h Height
 * @param w Width
 * @param nbMines Number of mines
 * @return the grid 
 */
void CreateGrid(int h, int w, int nbMines);

/**
 * @brief Create a Sommet object
 * 
 *
 * @return sommet 
 */
sommet createSommet();

/**
 * @brief 
 * 
 * @param h 
 * @param w 
 * @return true 
 * @return false 
 */
bool isInGrid(int h, int w);

/**
 * @brief 
 * 
 * @param h 
 * @param w 
 */
void PrintNInGrid(int h, int w);

/**
 * @brief Place randomly nbMines mines on the grid
 * 
 * @param nbMines 
 */
void placeMines(int nbMines);

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

extern Grid *grid;

#endif