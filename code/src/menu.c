#include<stdio.h>
#include <stdlib.h> //atoi
#include<menu.h>
#include <ctype.h> 
#include <unistd.h> // to use sleep for debug
#include <string.h> //strlen

//Global vars : AJOUTER extern UNE FOIS LE PROG FONCTIONNEL! 
unsigned int game_mode, auto_game_mode, nb_games, 
    grid_length, grid_width, mine_number;

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){ //EOF = End of File : On boucle tant qu'on n'a pas récupéré le caractère \n et le symbole EOF(fin de fichier), qui signifient tous deux "vous êtes arrivé à la fin du buffer". On s'arrête de boucler dès que l'on tombe sur l'un de ces deux caractères.
        c = getchar();
    }
}

int checkInt(int low_inter, int high_inter) {
    char tmp[100];
    unsigned int res = 0;
    
    while(res == 0) {
        if (fgets(tmp, 100, stdin) != NULL){
            //printf("len=%d\n", strlen(tmp)); // qd on regarde la taille on est toujours a + 1 car fgets ajoute  \n\0 --> le \n est compté
            if(strlen(tmp) > 3) {
                printf("Not a valid number, please retry\n==>");
                if(strlen(tmp) == 99) {
                    viderBuffer();
                }
            }
            else if(strstr(tmp, "exit")){
            printf("Bye!\n");
                _Exit(0);
            }
            else {
                res = atoi(tmp);
                if (res >=low_inter && res<=high_inter){
                    //printf("OK\n");
                    //printf("tmp = %s \n", tmp);
                    //printf("res=%d\n", res);
                } else if (res == 0){
                    printf("Not a valid number (can't be = 0), please retry\n==>");
                } else {
                    printf("Error, please select a number between %d and %d\n", low_inter, high_inter);
                    res = 0;
                }
            }
        }
    }
    return res;
}
/*
void check_int_input(char *N, int low_inter, int high_inter){
    int ii = 0;
    while (1) {
        fflush(stdin);
        ii = atoi(N); //if choice is a str : i == 0
        //printf("i=%d\n", i);
        //printf("*N=%s\n", N); //%s va chercher le *N
        //printf("Low : %d & High : %d\n", low_inter, high_inter);
        if(ii>=low_inter && ii<=high_inter){
            //printf("check input result=%d\n",ii);
            //*N = i + '0';
            //printf("*N = %s \n", N);
            return;
	    } else {
            printf("Error, please select a digit between %d and %d\n", 
            low_inter, high_inter);
            scanf("%s", N);
            ii = atoi(N);
        }
    }
} */

int config_game(){
    printf("\n--------- CONFIGURATION ---------\n");
    printf("General Game mode : 1. manual | 2. automatic\n:>");
    game_mode = checkInt(1,2);
    printf("General Game mode selected = %s\n\n", game_mode == 1 ? "manual" : "automatic");

    if (game_mode == 2){ // auto game mode
        printf("-----------------\n\n");
        printf("Automatic Game Mode : 1. spectator | 2. statistics\n:>");
        auto_game_mode = checkInt(1,2);
        printf("Automatic Game mode selected = %s\n\n", auto_game_mode == 1 ? "spectator" : "statistics");

        if (auto_game_mode == 2){ //stats game mode
            printf("-----------------\n\n");
            printf("Please choose the number of games on which stats will be made\n:>");
            nb_games = checkInt(1,20); // 20 games max
            printf("Number of Games = %d\n", nb_games);

            printf("Grid Length ? :>");
            grid_length = checkInt(1,30); // Length max = 30 
            printf("Length=%d\n", grid_length);

            printf("\nWidth ? :>");
            grid_width = checkInt(1,24); // Width max = 24
            printf("Width=%d\n", grid_width);

            printf("Number of Mines ? :>");
            mine_number = checkInt(1,grid_length*grid_width/2);
            printf("Mine Number=%d\n", mine_number);

            printf("-----------------\n\n");
            printf("RECAP \n");
            printf("Number of Games = %d\n", nb_games);
            printf("Grid Length=%d\n", grid_length);
            printf("Grid Width=%d\n", grid_width);

            printf("Number of Mines =%d\n", mine_number);

            _Exit(0);
        }
    }
    /*
    printf("-----------------\n\n");
    
    
    printf("Please choose the size of the grid : \n");

    printf("Length ? :>");
    scanf("%s", &grid_length);
    printf("str length=%s\n", &grid_length);
    check_int_input(&grid_length, 1, 30); // Length max = 30
    fflush(stdin);

    printf("\nWidth ? :>");
    scanf("%s", &grid_width);
    printf("str width=%s\n", &grid_width);
    check_int_input(&grid_width, 1, 24); // Width max = 24
        
    fflush(stdin);

    printf("\nFinal Length=%s\n", (&grid_length+2)); // avec +2 ça fonctionne ?? pourquoi ??
    printf("Final Width=%s\n", &grid_width);

    _Exit(0);
    }
    */
     
}

void welcome(){
    unsigned int choice;
    //int i;
    printf("======================\n");
    printf("****** 1. Play  ******\n");
    printf("****** 2. Exit  ******\n");
    printf("======================\n");
    
    // Read the next character in the input buffer
    printf("\nPlease select a choice :>");
    choice = checkInt(1,2);
        
    if (choice == 1){
        config_game();
        
    } else if (choice == 2){
        printf("Bye!\n");
        _Exit(0); //quit properly
    } /* else {
        printf("Error, please select either 1 or 2\n");
        sleep(2); //read error msg
        system("clear"); //system(): exec bash cmds
        welcome();
    } */
}

int main(int argc, char const *argv[]){
    welcome();
    return 0;
}

