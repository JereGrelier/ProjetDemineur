#include "../include/manual.h"
#include "../include/menu.h"

unsigned int game_mode, auto_game_mode, nb_games, grid_length, grid_width, mine_number;

int main(int argc, char* charv[]) {
    system("clear");
    welcome();
    CreateGrid(grid_length, grid_width, mine_number);
    if (!game_mode-1)
    {
        handleManualGame();
    }
    return 0;
}