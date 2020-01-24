#include <stdio.h>

int main(void){

    int user_num, m = 1;

    printf("Enter the integer to count to: ");
    scanf("%d", &user_num);

    while (m*m <= user_num){
        if (m % 2 == 0){
            printf("%d\n", m*m);
        }
        m++;
    }

    return 0;
}