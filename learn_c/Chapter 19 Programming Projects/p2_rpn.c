#include <stdio.h>
#include <ctype.h>
#include "stackadt.h"

int main(void){

    char ch;
    int temp;
    Stack s = create();

    make_empty(s);

    while(1){
        printf("Enter an RPN expression: ");
        scanf(" %c", &ch);

        if(ch == 'q'){
            break;
        } else {
            while(ch != '='){
                if(isdigit(ch)){
                    push(s, ch-'0');
                } else{
                    switch(ch){
                        case '+':
                            push(s, pop(s) + pop(s));
                            break;
                        case '-':
                            temp = pop(s);
                            push(s, pop(s) - temp);
                            break;
                        case '*':
                            push(s, pop(s) * pop(s));
                            break;
                        case '/':
                            temp = pop(s);
                            push(s, pop(s) / temp);
                            break;
                        default:
                            printf("Character not recognized: %c\n", ch);
                    }
                }
                scanf(" %c", &ch);
            }
            printf("Value of expression: %d\n", pop(s));
        }
    }   

    return 0;
}