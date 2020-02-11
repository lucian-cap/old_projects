#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void){

    char sen[SIZE], *beg, *end, check = 't';
    end = sen;

    printf("Enter a message: ");
    while((*end = getchar()) != '\n'){
        if(isalpha(*end)){
            *end = toupper(*end);
            end++;
        }
    }

    end--;
    beg = sen;
    while(beg <= end){
        if(*beg != *end){
            check = 'f';
            break;
        } else {
            beg++;
            end--;
        }
    }

    if(check != 't'){
        printf("Not a palindrome.");
    } else {
        printf("Palindrome.");
    }

    return 0;
}