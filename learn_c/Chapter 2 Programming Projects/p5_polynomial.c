#include <stdio.h>

int main(void){

    float ind;

    printf("Enter the value for x: ");
    scanf("%f", &ind);

    printf("The output of the polynomial is: %.2f", 3*ind*ind*ind*ind*ind + 2*ind*ind*ind*ind - 5*ind*ind*ind - ind*ind + 7*ind - 6);
    
    return 0;
}