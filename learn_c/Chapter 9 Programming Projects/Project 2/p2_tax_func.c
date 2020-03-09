#include <stdio.h>

double get_tax(double income);

int main(void){

    double income = 0;

    printf("Enter the amount of taxable income: ");
    scanf("%lf", &income);

    while(income <= 0.00f){
        printf("Enter the amount of taxable income: ");
        scanf("%lf", &income);
    }

    printf("Your tax due is $%.2lf", get_tax(income));

    return 0;
}

double get_tax(double income){
    double tax_amount = 0;

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

    return tax_amount;
}