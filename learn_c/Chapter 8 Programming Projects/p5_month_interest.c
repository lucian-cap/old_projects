#include <stdio.h>

#define INIT_LOAN 100.00f
#define NUM_LOAN ((int) (sizeof(amount)/sizeof(amount[0])))

int main(void){

    float interest;
    int num_year;
    double amount[5];

    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter number of years: ");
    scanf("%d", &num_year);

    printf("\nYears");
    for(int i = 0; i < NUM_LOAN; i++){
        printf("%13.2f%%", interest+i);
        amount[i] = INIT_LOAN;
    }

    printf("\n");

    for(int i = 1; i <= num_year; i++){
        printf("%4d", i);
        for(int month = 0; month < 12; month++){
            for(int loan = 0; loan < NUM_LOAN; loan++){
                amount[loan] += ((interest + loan) / 100.00f) * amount[loan];
            }
        }
        for(int loan=0; loan<NUM_LOAN;loan++){
            printf("%15.2f", amount[loan]);
        }
        printf("\n");
    }

    return 0;
}