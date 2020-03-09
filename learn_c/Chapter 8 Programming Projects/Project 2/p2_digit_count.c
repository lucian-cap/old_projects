#include <stdio.h>

int main(void){

    int digit[10] = {0};
    char dig;

    printf("Enter a number: ");

    while((dig = getchar()) != '\n'){
        digit[dig-'0']++;
    }

    printf("Digit:\t     ");
    for(int i = 0; i < 10; i++){
        printf("%3d", i);
    }

    printf("\nOccurrences: ");
    for(int i = 0; i < 10; i++){
        printf("%3d", digit[i]);
    }

    return 0;
}