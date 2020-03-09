#include <stdio.h>

struct date{
    int month;
    int day;
    int year;
};

struct date *compare_date(struct date *d1, struct  date *d2);

int main(void){

    struct date d1, d2, *early;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &d2.month, &d2.day, &d2.year);

    early = compare_date(&d1, &d2);

    printf("%02d/%02d/%02d is the earliest date.", early->month, early->day, early->year);

    return 0;
}

struct date *compare_date(struct date *d1, struct  date *d2){
    struct date *r_val;

    if((d1->year)<(d2->year)){
        r_val = d1;
    } else if((d2->year)<(d1->year)){
        r_val = d2;
    } else {
        if((d1->month)<(d2->month)){
            r_val = d1;
        } else if((d2->month)<(d1->month)){
            r_val = d2;
        } else {
            if((d1->day)<(d2->day)){
                r_val = d1;
            } else if((d2->day)<(d1->day)){
                r_val = d2;
            } else {
                r_val = d1;
            }
        }
    }

    return r_val;
}