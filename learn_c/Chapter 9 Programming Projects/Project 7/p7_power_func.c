#include <stdio.h>

int power(int x, int n);

int main(void){

    int value, exp;

    printf("Enter the base value: ");
    scanf("%d", &value);

    printf("Enter the exponent to raise it to: ");
    scanf("%d", &exp);

    printf("%d raised to the %d is: %d", value, exp, power(value, exp));

    return 0;
}

int power(int x, int n){
    int val;
    if (n == 0){
        val = 1;
    } else if (n % 2 == 0){
        val = power(x, n/2);
        val *= val;
    } else {
        val = x * power(x, n-1);
    }

    return val;
}