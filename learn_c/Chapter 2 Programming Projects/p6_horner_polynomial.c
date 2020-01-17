#include <stdio.h>

int main(void){

    float ind;

    printf("Please enter the value for x in the polynomial: ");
    scanf("%f", &ind);

    printf("The output of the polynomial is: %.2f", (((((3*ind + 2)*ind - 5)*ind - 1)*ind + 7)*ind - 6) );

    return 0;
}