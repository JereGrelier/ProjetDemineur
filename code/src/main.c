#include "../include/manual.h"
#include "../include/menu.h"

unsigned int game_mode, auto_game_mode, nb_games, grid_length, grid_width, mine_number;

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