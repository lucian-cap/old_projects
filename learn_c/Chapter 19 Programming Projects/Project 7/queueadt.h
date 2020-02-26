#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue create(void);
void destroy(Queue q);

void insert(Queue q, int n);
int pop(Queue q);
int peak(Queue q);
int last(Queue q);
bool is_empty(Queue q);

#endif