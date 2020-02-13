#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

void encrypt(char *message, int shift);

int main(void){

    char mes[MAX_LEN+1];
    int shift = 0;

    printf("Enter message to be encrypted: ");
    fgets(mes, MAX_LEN, stdin);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(mes, shift);

    printf("Encrypted message: %s", mes);

    return 0;
}

void encrypt(char *message, int shift){
    while(*message != '\0' && *message != '\n'){
        if(islower(*message)){
            *message = ((*message - 'a') + shift) % 26 + 'a';
        } else if(isupper(*message)){
            *message = ((*message - 'A') + shift) % 26 + 'A';
        }
        message++;
    }
}