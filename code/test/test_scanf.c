#include <stdio.h>
#include <stdlib.h> //atoi
#include <stdbool.h>
#include <string.h>

//Global vars : 
int nb_games, grid_length, grid_width, mine_number;

/*void check_int_input(int *N, int low_inter, int high_inter){
    while (true) {
        fflush(stdin);
        if(*N>=low_inter && *N<=high_inter){
            return;
	    } else {
            printf("Error, please select a digit between %d and %d\n", 
            low_inter, high_inter);
            scanf("%d", N);
        }
    }
} */


int checkInt() {
    char tmp[100];
    unsigned int res = 0;
    
    while(res == 0) {
        scanf("%s", tmp);
        printf("len=%d\n", strlen(tmp));
        if(strlen(tmp) > 10) {
            printf("Not a valid number, please retry\n==>");
        }
        else if(strstr(tmp, "exit")){
          printf("Bye!\n");
            _Exit(0);
        }
        else {
            res = atoi(tmp);
            if(res == 0)
                printf("Not a valid number, please retry\n==>");
        }
    }
    return res;
}

int main(int argc, char const *argv[]){
   /*char str[100];
   sprintf(str, "%d", 5);
   printf("%d\n", str);
   */
   printf("Please choose the number of games on which stats will be made\n:>");
   nb_games = checkInt();

   printf("nbgames=%d\n", nb_games);

  /*
   int err_code;
   printf("-----------------\n\n");
   printf("Please choose the number of games on which stats will be made\n:>");
   err_code=scanf("%d", &nb_games);

   printf("errcode=%d\n", err_code);
   printf("sizeof(int)=%d\n", sizeof(int));
   printf("sizeof(nbgames)=%d\n", sizeof(nb_games));


   if(err_code == 1) {
      printf("Syntaxe OK\n");
   } else {
      printf("Syntaxe KO\n");
      _Exit(0);
   }

   check_int_input(&nb_games, 1, 100);

   printf("NB Games = %d\n", nb_games);



   */
   _Exit(0);
}
