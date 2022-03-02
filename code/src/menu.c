#include<stdio.h>
#include <stdlib.h>
#include<menu.h>
#include <ctype.h> 

int config_game(){
    printf("CONFIG GAME OK\n");
    return 0;
}

void welcome(){
    printf("*************************\n");
    printf("****** 1.play ******\n");
    printf("****** 0.exit ******\n");
    printf("*************************\n");
    printf(" Please select a :>");
    int choice = 2;
    scanf("%d", &choice);
    if (choice == 1){
    config_game();
    } else if (choice == 0) {
        printf("Bye!\n");
    } else {
        printf("Input error, please retry!");
        welcome();
    }
}

int main(int argc, char const *argv[]){
    welcome();
    return 0;
}

