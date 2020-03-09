#include <stdio.h>

int main(void){

    int og_num, num, count = 0;
 
    printf("Enter the integer: ");
    scanf("%d", &og_num);

    num = og_num;

    do {
        num /= 10;
        count++;
    } while (num != 0);

    printf("The integer %d has %d digits.", og_num, count);

    return 0;
}