#include <stdio.h>

int main(void){

    int digit[10] = {0}, check = 0;
    char dig;

    printf("Enter a number: ");
    
    while ((dig = getchar()) != '\n'){
        digit[dig-'0']++;
    }

    printf("Repeated digit(s):");
    for(int i = 0; i < 10; i++){
        if (digit[i] > 1){
            printf(" %d", i);
            check++;
        }
    }
    
    if (check == 0){
        printf(" No repeated digits.");
    }

    return 0;
}