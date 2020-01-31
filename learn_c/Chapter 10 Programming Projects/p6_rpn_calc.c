#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

void empty(void), push(int i);
bool is_full(void), is_empty(void);
int pop(void);

int stack[SIZE];
int top = 0;

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

void empty(void){
    top = 0;
}

bool is_full(void){
    return top == SIZE;
}

bool is_empty(void){
    return top == 0;
}

void push(int i){
    if (is_full()){
        printf("Stack Overflow. Terminating.");
        exit(1);
    } else {
        stack[top] = i;
        top++;
    }
}

int pop(void){
    if(is_empty()){
        printf("Stack Underflow. Terminating.");
        exit(1);
    } else {
        return stack[--top];
    }
}