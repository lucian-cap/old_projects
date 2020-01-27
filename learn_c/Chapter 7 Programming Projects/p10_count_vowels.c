#include <stdio.h>
#include <ctype.h>

int main(void){

    char ch;
    int count = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n'){
        ch = toupper(ch);
        switch(ch){
            case 'A': case 'I': case 'E': case 'O': case 'U': count++; break;
        }
    }

    printf("Your sentence contains %d vowels.", count);

    return 0;
}