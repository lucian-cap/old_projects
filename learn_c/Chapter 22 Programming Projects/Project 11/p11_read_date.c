#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int mon, day, year;

    if(argc != 2){
        printf("Please enter ONE date on the command line to use this program.\n");
        exit(EXIT_FAILURE);
    }

    if(sscanf(argv[1], "%d/%d/%d", &mon, &day, &year) != 3){
        sscanf(argv[1], "%d-%d-%d", &mon, &day, &year);
    }

    switch(mon){
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
        default:
            printf("Month not recognized. Please try again with a valid month.\n");
            exit(EXIT_FAILURE);
    }
    printf("%d, %d\n", day, year);

    return 0;
}