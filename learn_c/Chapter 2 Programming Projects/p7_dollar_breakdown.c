#include <stdio.h>

int main(void){

    int dollar;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);

    int num_20 = dollar / 20;
    dollar -= 20*num_20;

    int num_10 = dollar / 10;
    dollar -= 10*num_10;

    int num_5 = dollar / 5;
    dollar -= 5*num_5;

    printf("$20 bills: %d\n", num_20);
    printf("$10 bills: %d\n", num_10);
    printf(" $5 bills: %d\n", num_5);
    printf(" $1 bills: %d\n", dollar);

    return 0;
}