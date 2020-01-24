#include <stdio.h>

int main(void){

    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if (hour == 0){
        printf("Equivalent 12-hour time: 12:%d AM.", minute);
    } else if (hour == 12){
        printf("Equivalent 12-hour time: 12:%d PM.", minute);    
    } else if (hour > 12){
        printf("Equivalent 12-hour time: %d:%d PM.", hour-12, minute);
    } else{
        printf("Equivalent 12-hour time: %d:%d AM.", hour, minute);
    }

    return 0;
}