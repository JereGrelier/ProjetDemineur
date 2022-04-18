/**
 * @file end.h
 * @author Jeremy Grelier (jeremy.grelier@enseirb-matmeca.fr)
 * @brief The source file for the end game
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef END_H
#define END_H

#include <stdlib.h>
#include <stdio.h>
#include "grid.h"

/**
 * @brief Display the end menu
 * 
 */
void DisplayEnd();


/**
 * @brief Handles the choice in end menu
 * 
 */
void handleEndGame();


/**
 * @brief Allows to replay with the same parameters
 * 
 */
void handleReplay();

#endif