#include <stdio.h>

int main(void){

    char f1, ch;

    printf("Enter a first and last name: ");
    scanf(" %c", &f1);

    while((ch = getchar()) != ' ');
    while((ch = getchar()) == ' ');

    do {
        putchar(ch);
    } while ((ch = getchar()) != ' '  && ch != '\n');

    printf(", %c.", f1);

    return 0;
}