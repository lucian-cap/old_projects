#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void){

    char sen[SIZE], ch;
    int beg = 0, end = 0;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            sen[end] = toupper(ch);
            end++;
        }
    }
    end--;

    while(beg <= end){
        if(sen[beg] != sen[end]){
            beg = -1;
            break;
        } else {
            beg++;
            end--;
        }
    }

    if(beg == -1){
        printf("Not a palindrome.");
    } else {
        printf("Palindrome.");
    }

    return 0;
}