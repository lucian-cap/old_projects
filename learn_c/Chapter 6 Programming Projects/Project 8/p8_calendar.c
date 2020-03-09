#include <stdio.h>

int main(void){

    int num_days, start_day;

    printf("Enter number of days in month: ");
    scanf("%d", &num_days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    for (int i = 1; i <= num_days+start_day-1; i++){
        if (i >= start_day){
            printf("%2d ", i-start_day+1);
        } else {
            printf("   ");
        }

        if (i % 7 == 0){
            printf("\n");
        }
    }


    return 0;
}