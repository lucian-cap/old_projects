#include <stdio.h>

int main(void){

    int num11, num12, num13, num14, num21, num22, num23, num24, num31, num32, num33, num34, num41, num42, num43, num44;

    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
            &num11, &num12, &num13, &num14, &num21, &num22, &num23, &num24, &num31, &num32, &num33, &num34, &num41, &num42, &num43, &num44);

    printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n\n", 
            num11, num12, num13, num14, num21, num22, num23, num24, num31, num32, num33, num34, num41, num42, num43, num44);

    printf("Row sums: %d %d %d %d\n", num11+num12+num13+num14, num21+num22+num23+num24, num31+num32+num33+num34, num41+num42+num43+num44);
    printf("Column sums: %d %d %d %d\n", num11+num21+num31+num41, num12+num22+num32+num42, num13+num23+num33+num43, num14+num24+num34+num44);
    printf("Diagonal sums: %d %d", num11+num22+num33+num44, num41+num32+num23+num14);

    return 0;
}