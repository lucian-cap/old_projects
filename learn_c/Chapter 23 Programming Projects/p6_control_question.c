#include <stdio.h>
#include <ctype.h>

int main(void){

    char ch;

    while((ch = getchar()) != EOF){
        if(isprint(ch) || ch == '\n'){
            putchar(ch);
        } else {
            putchar('?');
        }
    }

    return 0;
}