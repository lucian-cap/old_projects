#include <stdio.h>
#include <ctype.h>

#define SIZE 80

int main(void){

    char mes[SIZE], ch;
    int count = 0, shift;

    printf("Enter message to be encrypted: ");

    while((ch = getchar()) != '\n'){
        mes[count] = ch;
        count++;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    for(int i = 0; i < count; i++){
        if(isupper(mes[i])){
            printf("%c", ((mes[i] - 'A') + shift) % 26 + 'A');
        } else if (islower(mes[i])){
            printf("%c", ((mes[i] - 'a') + shift) % 26 + 'a');
        } else {
            printf("%c", mes[i]);
        }
    }

    return 0;
}