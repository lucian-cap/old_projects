#include <stdio.h>

int main(void){

    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
    int sum1, sum2;

    printf("Enter the UPC number to check: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
    &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12);

    sum1 = num1+num3+num5+num7+num9+num11;
    sum2 = num2+num4+num6+num8+num10;

    sum1 = 9 - (((sum2 + sum1 * 3) - 1) % 10); 

    if (sum1 != num12){
        printf("This UPC number is not valid.");
    } else{
        printf("This UPC number is valid.");
    }


    return 0;
}