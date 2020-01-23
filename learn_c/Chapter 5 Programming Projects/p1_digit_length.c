#include <stdio.h>

int main(void){

    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 10){
        printf("The number %d has 1 digit.", num);
    } else if (num < 100){
        printf("The number %d has 2 digits.", num);        
    } else if (num < 1000){
        printf("The number %d has 3 digits.", num);
    } else{
        printf("The number %d has 4 digits.", num);
    }


    return 0;
}