#include<stdio.h>
#include <stdlib.h>
#include<menu.h>
#include <ctype.h> 
#include <unistd.h> // to use sleep for debug

/* OLD FUNC
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
            // *N = i + '0';
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

int config_game(int *g_mode, int *auto_g_mode, int *s_mode,
int *size, int *m_number){
    printf("--------- CONFIGURATION ---------\n");
    printf("Game mode : 1. manual | 2. automatic\n");
    return 0;
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
        system("clear"); //system(): exec bash cmds
        welcome();
    }
}

int main(int argc, char const *argv[]){
    welcome();
    int game_mode, auto_game_mode=0, spec_mode=0, 
    grid_size, mine_number;
    return 0;
}