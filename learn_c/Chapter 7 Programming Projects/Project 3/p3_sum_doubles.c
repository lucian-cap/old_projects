#include <stdio.h>

int main(void){

    double n, sum = 0.00l;

    printf("This program sums a series of doubles.\n");
    printf("Enter doubles (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0.00l){
        sum += n;
        scanf("%lf", &n);
    }

    printf("The sum is %lf.\n", sum);


    return 0;
}