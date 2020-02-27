#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void){

    struct s test;

    printf("Size of member 'a': %d\nSize of member 'b': %d\nSize of member 'c': %d\n", sizeof(test.a), sizeof(test.b), sizeof(test.c));

    printf("Offset of member 'a': %d\nOffset of member 'b': %d\nOffset of member 'c': %d\n", offsetof(struct s, a), offsetof(struct s, b), offsetof(struct s, c));

    printf("Size of struct s: %d", sizeof(struct s));

    return 0;
}