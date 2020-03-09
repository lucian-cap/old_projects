#include <stdio.h>

int main(void){

    long user_val;
    int digit[10] = {0}, count = 0;

    printf("Enter a number: ");
    scanf("%ld", &user_val);

    while(user_val > 0){
        while(user_val > 0){
            digit[user_val%10]++;
            user_val /= 10;
        }

        printf("Repeated digit(s): ");

        for(int i = 0; i < 10; i++){
            if (digit[i] > 1){
                printf(" %d", i);
                count++;
            }
            digit[i] = 0;
        }

        if(count == 0){
            printf("No repeated digits.");
        }

        printf("\nEnter a number: ");
        scanf("%ld", &user_val);

        count = 0;
    }

    return 0;
}