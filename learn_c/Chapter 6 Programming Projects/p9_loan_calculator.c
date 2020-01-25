#include <stdio.h>

int main(void){

    float loan_amount, interest_rate, month_pay;
    int num_pay;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &month_pay);
    printf("Enter the number of payments: ");
    scanf("%d", &num_pay);

    interest_rate = (interest_rate / 100.00f) / 12.00f;

    for (int i = 1; i <= num_pay; i++){
        loan_amount *= (1.00f + interest_rate);
        loan_amount -= month_pay;
        printf("Balance remaining after %d payment(s): %.2f\n", i, loan_amount);
    }


    return 0;
}