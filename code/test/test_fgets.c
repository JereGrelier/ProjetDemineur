#include <stdio.h> //fgets()
#include <stdlib.h> //atoi
#include <stdbool.h>
#include <string.h>

//Global vars : 
unsigned int nb_games, grid_length, grid_width, mine_number;

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
            printf("len=%d\n", strlen(tmp)); // qd on regarde la taille on est toujours a + 1 car fgets ajoute  \n\0 --> le \n est compté
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
                    printf("OK\n");
                    printf("tmp = %s \n", tmp);
                    printf("res=%d\n", res);
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

int main(int argc, char const *argv[]){
   /*char str[100];
   sprintf(str, "%d", 5);
   printf("%d\n", str);
   */
   printf("Please choose the number of games on which stats will be made\n:>");
   nb_games = checkInt(1, 20);

   printf("\nnbgames=%d\n", nb_games);

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
