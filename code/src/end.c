#include <stdlib.h>
#include <stdio.h>
#include "../include/end.h"
#include "../include/menu.h"

void handleReplay() {
    printf("SoonTm\n");
    _Exit(0);
}

void handleEndGame() {
    printf("\n\n");
    printf("What do you want to do?\n");
    printf("1. Replay with same parameters\n");
    printf("2. Go back to main menu\n");
    printf("3. Exit the game\n ==>");
    int choice = checkInt(1,3);
    switch (choice)
    {
    case 1:
        handleReplay();
        break;
    case 2:
        break;
    case 3:
        system("clear");
        _Exit(0);
    default:
        break;
    }
}