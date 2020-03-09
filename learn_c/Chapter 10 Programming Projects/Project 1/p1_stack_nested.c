#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

void make_empty(void), push(char i);
bool is_empty(void), is_full(void);
char pop(void);

char stack[SIZE], ch;
int loc = 0;

int main(void){

    bool nested = true;
    char ch;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n'){
        if (ch == '(' || ch == '{'){
            push(ch);
        } else if (ch == ')'){
            if (pop() != '('){
                nested = false;
                break;
            }
        } else if (ch == '}'){
            if (pop() != '{'){
                nested = false;
                break;
            }
        }
    }

    if (nested && !is_empty()){
        nested = false;
    }

    if (nested){
        printf("Parentheses/braces are nested properly.");
    } else {
        printf("Parentheses/braces are not nested properly.");
    }

    return 0;
}

void make_empty(void){
    loc = 0;
}

bool is_empty(void){
    return loc == 0;
}

bool is_full(void){
    return loc == SIZE;
}

void push(char i){
    if (is_full()){
        printf("Stack overflow.");
        exit(1);
    } else {
        stack[loc++] = i;
    }
}

char pop(void){
    if (is_empty()){
        return '\n';
    } else {
        return stack[--loc];
    }
}