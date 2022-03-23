#include<stdio.h>
#include <stdlib.h> //atoi
#include<menu.h>
#include <ctype.h> 
#include <string.h> // itoa
#include <unistd.h> // to use sleep for debug

//Global vars : 
char game_mode=0, auto_game_mode=0, spec_mode=0, 
    grid_size, mine_number;

void check_int_input(char *N, int low_inter, int high_inter){
    int i = 0;
    while (1) {
        i = atoi(N); //if choice is a str : i == 0
        printf("i=%d\n", i);
        printf("*N=%s\n", N); //%s va chercher le *N
        printf("Low : %d & High : %d\n", low_inter, high_inter);
        if(i>=low_inter && i<=high_inter){
            printf("check input result=%d\n",i);
            *N = i + '0';
            return;
	    } else {
            printf("Error, please select a digit between %d and %d\n", 
            low_inter, high_inter);
            scanf("%s", N);
            i = atoi(N);
        }
    }
}

int config_game(char *g_mode){
    printf("\n--------- CONFIGURATION ---------\n");
    printf("Game mode : 1. manual | 2. automatic\n:>");
    scanf("%s", g_mode);
    check_int_input(g_mode, 1, 2);
    printf("Game mode selected = %s\n", *g_mode == '1' ? "manual" : "automatic");

    /*if (*g_mode == '2'){
        printf("Automatic game mode : 1. spectator | 2. statistics\n:>");
        scanf("%s", g_mode);
        check_int_input(g_mode, 1, 2);
        printf("Game mode selected = %s\n", *g_mode == '1' ? "manual" : "automatic");
    }*/
    _Exit(0);
}

void welcome(){
    printf("======================\n");
    printf("****** 1. Play  ******\n");
    printf("****** 2. Exit  ******\n");
    printf("======================\n");
    char choice;
    int i;
    // Read the next character in the input buffer
    printf("\nPlease select a choice :>");
    scanf("%s", &choice);

    i = atoi(&choice); //if choice is a str : i == 0
        
    if (i == 1){
        config_game(&game_mode);
        
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

