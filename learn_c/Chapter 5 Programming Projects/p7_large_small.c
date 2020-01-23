#include <stdio.h>

int main(void){

    int num1, num2, num3, num4, max1, min1, max2, min2;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

    if (num1 < num2){
        max1 = num2;
        min1 = num1;
    } else{
        max1 = num1;
        min1 = num2;
    }

    if (num3 < num4){
        max2 = num4;
        min2 = num3;
    } else {
        max2 = num3;
        min2 = num4;
    }

    if (max1 < max2){
        max1 = max2;
    }
    if (min1 > min2){
        min1 = min2;
    }

    printf("Largest: %d\n", max1);
    printf("Smallest: %d\n", min1);


    return 0;
}