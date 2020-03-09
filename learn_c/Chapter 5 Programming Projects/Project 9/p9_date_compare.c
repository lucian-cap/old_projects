#include <stdio.h>

int main(void){

    int d1_mon, d1_day, d1_year, d2_mon, d2_day, d2_year, d1, d2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1_mon, &d1_day, &d1_year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2_mon, &d2_day, &d2_year);

    d1 = d1_mon * 30 + d1_day + d1_year * 365;
    d2 = d2_mon * 30 + d2_day + d2_year * 365;

    if (d1 < d2){
        printf("%d/%d/%d is earlier.", d1_mon, d1_day, d1_year);
    } else {
        printf("%d/%d/%02d is earlier.", d2_mon, d2_day, d2_year);
    }

    return 0;
}