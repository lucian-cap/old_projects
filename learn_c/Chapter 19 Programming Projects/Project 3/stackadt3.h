#ifndef STACKADT3_H
#define STACKADT3_H

#include <stdbool.h>

typedef struct stack_type *Stack;
typedef int Item;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);
int length(Stack s);

#endif