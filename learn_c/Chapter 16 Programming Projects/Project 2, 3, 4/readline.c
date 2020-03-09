#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int read_line(char *name, const int max_len){
    char ch;
    int i = 0;

    while(isspace(ch = getchar()));

    while(ch != '\n' && ch != EOF){
        if(i < max_len){
            *name = ch;
            i++;
            name++;
        }
        ch = getchar();
    }
    *name = '\0';
    return ++i;

}