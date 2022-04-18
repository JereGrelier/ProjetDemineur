/**
 * @file grid.h
 * @author  Jeremy Grelier (Jeremy Grelier@enseirb-matmeca.fr)
 * @brief The source file for the grid & cells
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
    /**
     * @brief The number of mines around the cell
     * 
     */
    int nbMineAround;

    bool mined;

    /**
     * @brief 1 if discovered, 2 if flagged, 0 else
     * 
     */
    int state;
};

struct grid {
    /**
     * @brief A 2 dimension matrix for the cells, a cell is called with "grid[h][w]"
     * 
     */
    sommet ** sommet;

    int height;

    int width;

    /**
     * @brief The total number of mines in the grid
     * 
     */
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

extern Grid *grid;

#endif