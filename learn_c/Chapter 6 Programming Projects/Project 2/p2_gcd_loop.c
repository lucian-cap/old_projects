#include <stdio.h>

int main(void){

    int num1, num2, rem;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2){
        num2 = num2 + num1;
        num1 = num2 - num1;
        num2 = num2 - num1;
    }

    if (num1 == num2){
        printf("Greatest common divisor: %d", num1);
    } else {
        while (num1 != 0){
            rem = num2 % num1;
            num2 = num1;
            num1 = rem;
        }
        printf("Greatest common divisor: %d", num2);
    }

    return 0;
}