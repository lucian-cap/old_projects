#include <stdio.h>
#include <time.h>

int main(void){

    struct tm og_date;
    int day_shift, time;

    og_date.tm_sec = og_date.tm_min = og_date.tm_hour = 0;
    og_date.tm_isdst = -1;

    printf("Enter the month: ");
    scanf("%d", &og_date.tm_mon);
    og_date.tm_mon--;

    printf("Enter the day: ");
    scanf("%d", &og_date.tm_mday);

    printf("Enter the year: ");
    scanf("%d", &og_date.tm_year);
    og_date.tm_year -= 1900;

    printf("Enter the number of days to shift by: ");
    scanf("%d", &day_shift);
    og_date.tm_mday += day_shift;

    mktime(&og_date);
    printf("The shifted date is %d/%d/%d", og_date.tm_mon+1, og_date.tm_mday, og_date.tm_year+1900);

    return 0;
}