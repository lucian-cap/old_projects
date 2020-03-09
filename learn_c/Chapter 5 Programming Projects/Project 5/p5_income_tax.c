#include <stdio.h>

int main(void){

    float income, tax_amount;

    printf("Enter your taxable income: ");
    scanf("%f", &income);

    if (income < 750.00f){
        tax_amount = .01f * income;
    } else if (income < 2250.00f){
        tax_amount = 7.50f + .02f * (income - 750);
    } else if (income < 3750.00f){
        tax_amount = 37.50f + .03f * (income - 2250);
    } else if (income < 5250.00f){
        tax_amount = 82.50f + .04f * (income - 3750);
    } else if (income < 7000.00f){
        tax_amount = 142.50f + .05f * (income - 5250);
    } else {
        tax_amount = 230.00f + .06f * (income - 7000);
    }

    printf("The tax amount for an income of $%.2f is: %.2f", income, tax_amount);

    return 0;
}