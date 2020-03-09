#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;
    int item, mon, day, year;
    float price;

    if(argc != 2){
        printf("Error: to use this program, please enter ONE filename.\n");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("%s could not be opened. Please try again with a valid file.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item        Unit Price      Purchase Date\n");

    while(1){
        fscanf(fp, " %d,%f,%d/%d/%d", &item, &price, &mon, &day, &year);
        printf("%-5d\t\t%4.2f\t\t%d/%d/%d\n", item, price, mon, day, year);

        if(feof(fp)){
            break;
        }
    }


    return 0;
}