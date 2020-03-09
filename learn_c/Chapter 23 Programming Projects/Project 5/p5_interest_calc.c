#include <stdio.h>
#include <math.h>

int main(void){

    float og_loan, interest_rate, num_years;

    printf("Enter the original account amount: ");
    scanf(" %f", &og_loan);

    printf("Enter the interest rate: ");
    scanf(" %f", &interest_rate);

    printf("Enter the number of years the account has been gaining interest: ");
    scanf(" %f", &num_years);

    printf("The savings account is now worth: $%.2f", og_loan*exp((interest_rate/100)*num_years));

    return 0;
}