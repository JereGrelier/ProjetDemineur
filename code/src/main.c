/**
 * @file main.c
 * @author Jeremy Grelier (jeremy.grelier@enseirb-matmeca.fr)
 * @brief The main file for the game
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/manual.h"
#include "../include/menu.h"

int main(int argc, char* charv[]) {
    begin();
    if (!game_mode-1)
    {
        if(game_mode == 2) {
            return 0;
        }
        handleManualGame();
    }
    return 0;
}