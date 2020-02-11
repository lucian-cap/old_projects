#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void){

    int num, den;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    reduce(num, den, &num, &den);

    printf("In lowest terms: %d/%d", num, den);


    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator){
    int m, n, remainder;
    m = numerator;
    n = denominator;

    m = (numerator > denominator) ? numerator : denominator;
    n = (numerator < denominator) ? numerator : denominator;

    printf("%d %d", m, n);

    while(n != 0){
        remainder = m % n;
        m = n;
        n = remainder;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}