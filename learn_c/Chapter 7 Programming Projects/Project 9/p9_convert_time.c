#include <stdio.h>

int main(void){

    int hour, min;
    char t1, t2;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c%c", &hour, &min, &t1, &t2);

    if (t1 == 'A'){
        if (hour == 12){
            hour = 0;
        }
        printf("Equivalent 24-hour time: %d:%02d", hour, min);
    } else if (t1 == 'P'){
        if (hour != 12){
            hour += 12;
        }
        printf("Equivalent 24-hour time: %d:%02d", hour, min);
    } else{
        printf("The time format entered was not recognized.\n");
    }


    return 0;
}