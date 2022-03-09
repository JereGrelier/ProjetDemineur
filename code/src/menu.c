#include<stdio.h>
#include <stdlib.h>
#include<menu.h>
#include <ctype.h> 
#include <unistd.h> // to use sleep for debug

//https://stackoverflow.com/questions/49460307/using-fgets-and-strtol-to-get-a-single-integer
//https://openclassrooms.com/forum/sujet/equivalent-de-fgets-pour-les-int
int config_game(){
    printf("CONFIG GAME OK\n");
    return 0;
}

void printWelcome() {
    printf("======================\n");
    printf("****** 1. Play  ******\n");
    printf("****** 0. Exit  ******\n");
    printf("======================\n");
}

void welcome(int hasError){
    //printf("%d\n",hasError);
    if(hasError < 2)
        printWelcome();
    printf("\nPlease select a choice :>");
    int choice = 5;
    int scanf_return = scanf("%d", &choice);
    //atoi(choice); //test
    //printf("choice=%d\n", choice); //for debug var
    //printf("scanf_returned:%d\n", scanf_return); //for debug var
    //sleep(1);

    if (scanf_return == 1){
        if (choice == 1){
            config_game();
        } else if (choice == 0) {
            printf("Bye!\n");
        } else {
            if (hasError < 1)
                printf("\nPlease select a valid integer between 0 and 1!\n");
            welcome(hasError+1);
        }
    } else { //if str
        if (hasError < 1){
            printf("\nPlease enter a valid integer between 0 and 1!\n");
            printWelcome();
        }
        do {
            choice = getchar();
        }
        while (!isdigit(choice) || choice=='\0');
        ungetc(choice,stdin);
        welcome(hasError+2);
    }
}

int main(int argc, char const *argv[]){
    welcome(0);
    return 0;
}

