#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "p5_stack.h"

int main(void){

    char ch;
    int num1;

    printf("Enter an RPN expression: ");
    scanf(" %c", &ch);

    while(ch != 'q'){
        if(isdigit(ch)){
            push((int)ch - (int)'0');
        } else {
            switch(ch){
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    num1 = pop();
                    push(pop() - num1);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    num1 = pop();
                    push(pop() / num1);
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop());
                    printf("Enter an RPN expression: ");
                    break;
            }
        }

        scanf(" %c", &ch);
    }

    return 0;
}