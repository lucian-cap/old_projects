#include <stdio.h>
#include <stdlib.h>
#include "queueadt.h"

struct node {
    int data;
    struct node *next;
};

struct queue_type{
    struct node *front;
    struct node *end;
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

    q->front = NULL;
    q->end = NULL;
    q->len = 0;
    return q;
}

void destroy(Queue q){
    while(!is_empty(q)){
        pop(q);
    }
    free(q);
}

void insert(Queue q, int n){
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        terminate("Error in insert: queue is full.");
    }

    new_node->data = n;
    new_node->next = NULL;

    if(is_empty(q)){
        q->front = q->end = new_node;
    } else{
        q->end->next = new_node;
        q->end = new_node;
    }
    q->len++;
}

int pop(Queue q){
    int r_val;
    struct node *front;
    
    if(is_empty(q)){
        terminate("Error in pop: queue is empty.");
    } else{
        front = q->front;
        r_val = front->data;
        if(front == q->end){
            q->front = q->end = NULL;
        } else {
            q->front = front->next;
        }
        free(front);
        q->len--;
        return r_val;
    }
}

int peak(Queue q){
    return q->front->data;
}

int last(Queue q){
    return q->end->data;
}

bool is_empty(Queue q){
    return q->len == 0;
}

