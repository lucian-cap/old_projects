#include <stdio.h>

int main(void){

    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
            &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11);

    printf("Check digit: %d", num1+num3+num5+num7+num9);


    return 0;
}