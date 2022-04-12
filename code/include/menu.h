#ifndef MENU_H
#define MENU_H

extern unsigned int game_mode, auto_game_mode, nb_games, grid_length, grid_width, mine_number;

/**
 * @brief Choose to play a game or quit the prog
 * 
 */
void welcome();

/**
 * @brief Choose game mode, grid length, nb mines ...}
 * 
 * @return int 
 */
int config_game();


#endif /*MENU_H*/