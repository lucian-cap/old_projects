#include <stdio.h>

int main(void){

    int frac1_num, frac1_den, frac2_num, frac2_den;

    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &frac1_num, &frac1_den, &frac2_num, &frac2_den);

    printf("The sum is %d/%d", frac1_num*frac2_den+frac2_num*frac1_den, frac1_den*frac2_den);

    return 0;
}