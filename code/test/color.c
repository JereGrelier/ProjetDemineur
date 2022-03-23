#include <stdio.h>

int main(int argc, char const *argv[]){
    printf("\033[1;31m"); //Set the text to the color red : 0 = normal ; 1 = bold
    printf("Hello\n"); //Display Hello in red
    printf("\033[0m"); //Resets the text to default color
    return 0;
}
