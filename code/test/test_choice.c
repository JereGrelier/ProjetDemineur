#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int intToAscii(int number) {
   return '0' + number;
}

int main() 
{
    char choice;
    int i;
    while (1) {
        // Read the next character in the input buffer
        printf("Please enter a single digit\n->");
        scanf("%s", &choice);

        printf("%d\n",atoi(&choice));

        i = atoi(&choice); //if str i == 0
        //printf("%d\n",i);
        
        if(i>=0 && i<=9){ 
            printf("Single digit number=%d\n",i);
	    } else {
            printf("Error, this isn't a single digit\n");
        }
    }
    return 0;
}