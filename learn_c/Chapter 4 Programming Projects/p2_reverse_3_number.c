#include <stdio.h>

int main(void){

    int num;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    printf("The reversal is: %d%d%d", num%10, (num%100)/10, num/100);

    return 0;
}