#include <stdio.h>

#define SIZE 100

int main(void){

    char sen[SIZE];
    char *pos = sen;

    printf("Enter a message: ");
    while((*pos = getchar()) != '\n'){
        pos++;
    }

    printf("Reversal is: ");
    while(pos >= &sen[0]){
        printf("%c", *pos);
        pos--;
    }

    return 0;
}