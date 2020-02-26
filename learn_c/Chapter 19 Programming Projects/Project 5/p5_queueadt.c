#include <stdio.h>
#include <stdlib.h>
#include "queueadt.h"

#define MAX_LEN 20

struct queue_type {
    int data[MAX_LEN];
    int f_empty;
    int f_remove;
    int len;
};

void terminate(const char *mess){
    printf("%s\n", mess);
    exit(EXIT_FAILURE);
}

Queue create(void){
    Queue q = malloc(sizeof(struct queue_type));
    if(q == NULL){
        terminate("Error in create: stack could not be created.");
    }
    q->f_empty=0;
    q->f_remove=0;
    q->len=0;
    return q;
}

void destroy(Queue q){
    free(q);
}

void insert(Queue q, int n){
    if(q->len == MAX_LEN){
        terminate("Error in insert: queue is full.");
    }

    q->data[q->f_empty] = n;
    q->f_empty++;
    q->len++;

    if(q->f_empty == MAX_LEN){
        q->f_empty = 0;
    }
}

int pop(Queue q){
    if(q->len == 0){
        terminate("Error in pop: queue is empty.");
    }

    q->f_remove++;
    q->len--;

    if(q->f_remove == MAX_LEN){
        q->f_remove = 0;
        return q->data[MAX_LEN-1];
    } else{
        return q->data[q->f_remove-1];
    }
}

int peak(Queue q){
    return q->data[q->f_remove];
}

int last(Queue q){
    return q->data[q->f_empty-1];
}

bool is_empty(Queue q){
    return q->len == 0;
}