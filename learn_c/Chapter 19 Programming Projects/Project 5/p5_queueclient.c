#include <stdio.h>
#include "queueadt.h"

int main(void){
    int n;
    Queue q1 = create(), q2 = create();

    
    insert(q1, 1);
    insert(q1, 2);

    n = peak(q1);
    printf("Peaking at q1 yields: %d\n", n);
    n = pop(q1);
    printf("Popping q1 yields: %d\n", n);
    insert(q2, n);
    n = pop(q1);
    printf("Popping p1 yields: %d\n", n);
    insert(q2, n);

    destroy(q1);

    while(!is_empty(q2)){
        printf("Popping q2 yields: %d\n", pop(q2));
    }

    if(is_empty(q2)){
        printf("q2 is empty.\n");
    } else{
        printf("q2 is not empty.\n");
    }

    destroy(q2);
    
    return 0;
}