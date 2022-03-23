#include<stdio.h>
#include <stdlib.h> //atoi
#include<menu.h>
#include <ctype.h> 
#include <unistd.h> // to use sleep for debug

//Global vars : 
char game_mode=0, auto_game_mode=0, nb_games=1, 
    grid_length, grid_width, mine_number;

void check_int_input(char *N, int low_inter, int high_inter){
    int i = 0;
    while (1) {
        fflush(stdin);
        i = atoi(N); //if choice is a str : i == 0
        //printf("i=%d\n", i);
        //printf("*N=%s\n", N); //%s va chercher le *N
        //printf("Low : %d & High : %d\n", low_inter, high_inter);
        if(i>=low_inter && i<=high_inter){
            printf("check input result=%d\n",i);
            //*N = i + '0';
            //printf("*N = %s \n", N);
            return;
	    } else {
            printf("Error, please select a digit between %d and %d\n", 
            low_inter, high_inter);
            scanf("%s", N);
            i = atoi(N);
        }
    }
}

int config_game(char *gen_mode, char *auto_mode, char *nb_games){
    
    printf("\n--------- CONFIGURATION ---------\n");
    printf("General Game mode : 1. manual | 2. automatic\n:>");
    scanf("%s", gen_mode);
    check_int_input(gen_mode, 1, 2);
    printf("General Game mode selected = %s\n\n", *gen_mode == '1' ? "manual" : "automatic");
    
    if (*gen_mode == '2'){ // auto game mode
        printf("-----------------\n\n");
        printf("Automatic Game Mode : 1. spectator | 2. statistics\n:>");
        scanf("%s", auto_mode);
        check_int_input(auto_mode, 1, 2);
        printf("Automatic Game mode selected = %s\n\n", *auto_mode == '1' ? "spectator" : "statistics");

        if (*auto_mode == '2'){ //stats game mode
            printf("-----------------\n\n");
            printf("Please choose the number of games on which stats will be made\n:>");
            scanf("%s", nb_games);
            check_int_input(nb_games, 1, 100);
        }
    }
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

    printf("final length=%s\n", (&grid_length+2)); // avec +2 ça fonctionne ?? pourquoi ??
    printf("final width=%s\n", &grid_width);

    /*int tmp1, tmp2;
    tmp1 = atoi(&length);
    tmp2 = atoi(&width);

    printf("int length=%d\n", tmp1);
    printf("int width=%d\n", tmp2);
    */
    //grid_size_tmp = atoi(&length)*atoi(&width);


    //grid_size = length*width;
    //printf("%d\n", grid_size_tmp);

    _Exit(0);
}

void welcome(){
    char choice;
    int i;
    printf("======================\n");
    printf("****** 1. Play  ******\n");
    printf("****** 2. Exit  ******\n");
    printf("======================\n");
    
    // Read the next character in the input buffer
    printf("\nPlease select a choice :>");
    scanf("%s", &choice);

    i = atoi(&choice); //if choice is a str : i == 0
        
    if (i == 1){
        config_game(&game_mode, &auto_game_mode, &nb_games);
        
    } else if (i == 2){
        printf("Bye!\n");
        _Exit(0); //quit properly
    } else {
        printf("Error, please select either 1 or 2\n");
        sleep(3); //read error msg
        system("clear"); //system(): exec bash cmds
        welcome();
    }
}

int main(int argc, char const *argv[]){
    welcome();
    return 0;
}

