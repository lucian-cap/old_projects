#include <stdio.h>

#define MAX_LEN 100

void reverse(char *message);

int main(void){

    char sentence[MAX_LEN+1];

    printf("Enter a message: ");
    fgets(sentence, MAX_LEN, stdin);

    reverse(sentence);
    printf("Reversal is: %s", sentence);

    return 0;
}

void reverse(char *message){
    char *end = message, ch;

    while(*end != '\0' && *end != '\n'){
        end++;
    }
    end--;

    while(message < end){
        ch = *message;
        *message = *end;
        *end = ch;
        message++;
        end--;
    }
}