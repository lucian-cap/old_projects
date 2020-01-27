#include <stdio.h>

int main(void){

    int user_num, count=0;
    char ch;

    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in the table: ");
    scanf("%d", &user_num);
    getchar();

    for(long i = 1; i <= user_num; i++){
        if (count == 24){
            printf("Press Enter to continue...");
            getchar();
            count = 0;
        }
        printf("%10ld %10ld = %10ld\n", i, i, i*i);
        count++;
    }


    return 0;
}