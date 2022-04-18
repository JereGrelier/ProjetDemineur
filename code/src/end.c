#include <stdlib.h>
#include <stdio.h>
#include "../include/end.h"
#include "../include/menu.h"
#include "../include/manual.h"

unsigned int game_mode, auto_game_mode, nb_games, grid_length, grid_width, mine_number;

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