#include <stdio.h>

int main(void){

    float loan_amount;
    float interest_rate;
    float month_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &month_payment);

    interest_rate = 1 + (interest_rate/100.0f) / 12.0f;
    loan_amount *= interest_rate;
    
    printf("\nBalance remaining after first payment: %.2f\n", loan_amount-month_payment);
    loan_amount = (loan_amount - month_payment) * interest_rate;

    printf("Balance remaining after second payment: %.2f\n", loan_amount-month_payment);
    loan_amount = (loan_amount - month_payment) * interest_rate;

    printf("Balance remaining after third payment: %.2f\n", loan_amount-month_payment);

    return 0;
}