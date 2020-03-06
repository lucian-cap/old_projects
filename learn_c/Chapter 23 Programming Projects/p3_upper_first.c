#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){

    char ch;
    bool word_check = false;

    while((ch = getchar()) != EOF){
        if(word_check == false && isalpha(ch)){
            putchar(toupper(ch));
            word_check = true;
        } else if (isspace(ch)){
            putchar(ch);
            word_check = false;
        } else {
            putchar(ch);
        }
    }

    return 0;
}