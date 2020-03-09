#include <stdio.h>

int main(void){

    int item_num, mon, day, year;
    float unit_price;

    printf("Enter item number: ");
    scanf("%d", &item_num);

    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mon, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%-5d\t\t$%7.2f\t%.2d/%.2d/%d", item_num, unit_price, mon, day, year);
    
    return 0;
}