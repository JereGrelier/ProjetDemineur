/**
 * @file end.c
 * @author Jeremy Grelier (jeremy.grelier@enseirb-matmeca.fr)
 * @brief The file which handles the end of the game
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "../include/end.h"
#include "../include/menu.h"
#include "../include/manual.h"

void handleReplay() {
    CreateGrid(grid_length, grid_width, mine_number);
    if (!game_mode-1)
    {
        handleManualGame();
    }
}

void DisplayEnd() {
    printf("\n\n");
    printf("What do you want to do?\n");
    printf("1. Replay with same parameters\n");
    printf("2. Go back to main menu\n");
    printf("3. Exit the game\n ==>");
}

void handleEndGame() {
    DisplayEnd();
    int choice = checkInt(1,3);
    switch (choice)
    {
    case 1:
        handleReplay();
        break;
    case 2:
        begin();
        break;
    case 3:
        system("clear");
        _Exit(0);
    default:
        break;
    }
}