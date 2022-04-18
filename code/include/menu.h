/**
 * @file menu.h
 * @author Yoann Da Silva (ydasilva@enseirb-matmeca.fr)
 * @brief The source file to handle the main menu
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MENU_H
#define MENU_H

extern unsigned int game_mode, auto_game_mode, nb_games, grid_length, grid_width, mine_number;

/**
 * @brief Choose to play a game or exit
 * 
 */
void welcome();

/**
 * @brief Used to empty the C input buffer when an incorrect input (number) is submited by the user
 * 
 */
void viderBuffer();

/**
 * @brief Used to check if the input (number) submited by the user is included between the value interval [low_inter ; high_inter]
 * @param low_inter: Low interval number : must be >0
 * @param high_inter: High interval number : must be >0
 * @return a correct input based on user's choice
 */
int checkInt(int low_inter, int high_inter);

/**
 * @brief Choose game mode, grid length, number of mines ...
 * 
 * 
 */
void config_game();

/**
 * @brief Function to start configuring the game
 * 
 */
void begin();

#endif /*MENU_H*/