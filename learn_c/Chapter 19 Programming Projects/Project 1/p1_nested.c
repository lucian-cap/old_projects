#include <stdio.h>
#include "../stackadt.h"

int main(void){

    int ch, is_nested = 1;
    Stack s = create();

    printf("Enter parentheses and/or braces: ");
    while((ch = getchar()) != '\n'){
        if(ch == '(' || ch == '{'){
            push(s, ch);
        } else if (ch == ')' && pop(s) != '('){
            is_nested = 0;
            break;
        } else if (ch == '}' && pop(s) != '{'){
            is_nested = 0;
            break;
        }
    }

    if(!is_empty(s)){
        is_nested = 0;
    }

    switch(is_nested){
        case 0:
            printf("Parentheses/braces are not nested properly.\n");
            break;
        case 1:
            printf("Parentheses/braces are nested properly.\n");
            break;
    }

    return 0;
}