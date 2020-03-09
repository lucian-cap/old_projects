#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){

    char ch;
    bool char_found = false;

    while((ch = getchar()) != EOF){
        if(isspace(ch) && char_found == false){
            continue;
        } else if (ch == '\n' && char_found == true){
            putchar(ch);
            char_found = false;
        } 
        else {
            putchar(ch);
            char_found = true;
        }
    }

    return 0;
}