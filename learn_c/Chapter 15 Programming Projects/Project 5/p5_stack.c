#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int contents[MAX_SIZE], top = 0;

void empty(void){
    top = 0;
}

bool is_full(void){
    return top == MAX_SIZE;
}

bool is_empty(void){
    return top == 0;
}

void push(int i){
    if (is_full()){
        printf("Stack Overflow. Terminating.");
        exit(1);
    } else {
        contents[top] = i;
        top++;
    }
}

int pop(void){
    if(is_empty()){
        printf("Stack Underflow. Terminating.");
        exit(1);
    } else {
        return contents[--top];
    }
}