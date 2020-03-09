#include <stdio.h>

int main(void){

    int mon, day, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mon, &day, &year);

    printf("You entered the date %d%.2d%.2d\n", year, mon, day);

    return 0;
}