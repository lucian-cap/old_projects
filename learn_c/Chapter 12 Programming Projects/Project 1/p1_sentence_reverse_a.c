#include <stdio.h>

#define SIZE 100

int main(void){

    int count = 0;
    char sen[SIZE], ch;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n'){
        sen[count] = ch;
        count++;
    }

    printf("Reversal is: ");
    for(int i = count-1; i >= 0; i--){
        printf("%c", sen[i]);
    }

    return 0;
}