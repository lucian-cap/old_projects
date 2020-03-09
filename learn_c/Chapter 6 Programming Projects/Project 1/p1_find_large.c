#include <stdio.h>

int main(void){
    float num, max;

    printf("Enter a number: ");
    scanf("%f", &num);
    max = num;

    while (num > 0){
        if (num > max){
            max = num;
        }
        printf("Enter a number: ");
        scanf("%f", &num);
    }

    printf("The largest number entered was %f", max);

    return 0;
}