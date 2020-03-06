#include <stdio.h>
#include <time.h>

int main(void){

    struct tm d1, d2;
    time_t d1_con, d2_con;
    d1.tm_sec = d1.tm_min = d1.tm_hour = d2.tm_sec = d2.tm_min = d2.tm_hour = 0;
    d1.tm_isdst = d2.tm_isdst = -1;

    printf("Enter first date (in mon/dd/yyyy): ");
    scanf("%d/%d/%d", &d1.tm_mon, &d1.tm_mday, &d1.tm_year);
    d1.tm_mon--;
    d1.tm_year-=1900;

    printf("Enter second date (in mon/dd/yyyy): ");
    scanf("%d/%d/%d", &d2.tm_mon, &d2.tm_mday, &d2.tm_year);
    d2.tm_mon--;
    d2.tm_year-=1900;

    d1_con = mktime(&d1);
    d2_con = mktime(&d2);

    if(difftime(d1_con, d2_con) < 0){
        printf("%d/%d/%d came first.\n", d1.tm_mon+1, d1.tm_mday, d1.tm_year+1900);
    } else {
        printf("%d/%d/%d came first.\n", d2.tm_mon+1, d2.tm_mday, d2.tm_year+1900);
    }

    return 0;
}