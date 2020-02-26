#include <stdio.h>
#include "stackadt4.h"

int main(void){
    Stack s1, s2;
    void *n;

    s1 = create();
    s2 = create();

    push(s1, "s1 first push");
    push(s1, "s1 second push");

    n = pop(s1);
    printf("Popped '%s' from s1.\n", n);
    push(s2, n);
    n = pop(s1);
    printf("Popped '%s' from s1.\n", n);
    push(s2, n);

    destroy(s1);

    while(!is_empty(s2)){
        printf("Popped '%s' from s2.\n", pop(s2));
    }

    push(s2, "s2 last push");
    make_empty(s2);

    if(is_empty(s2)){
        printf("s2 is empty\n");
    } else {
        printf("s2 is not empty\n");
    }

    destroy(s2);

    return 0;
}