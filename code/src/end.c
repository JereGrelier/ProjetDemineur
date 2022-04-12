#include <stdlib.h>
#include <stdio.h>
#include "../include/end.h"


void handleEndGame() {
    printf("What do you want to do?\n");
    printf("1. Replay with same parameters\n");
    printf("2. Go back to main menu\n");
    printf("3. Exit the game");
    int choice = checkInt();
    switch (choice)
    {
    case 1:
        handleReplay();
        break;
    case 2:
    default:
        break;
    }
}