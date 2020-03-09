#include <stdio.h>

#define SIZE 100

int main(void){

    char sen[SIZE], *pos, *saved, end;
    pos = sen;

    printf("Enter a sentence: ");
    while((*pos = getchar()) != '\n'){
        pos++;
    }
    end = *(--pos);
    *pos = ' ';
    pos--;

    while(pos >= sen){
        if(*pos == ' '){
            saved = pos - 1;
            pos++;
            while(*pos != ' '){
                printf("%c", *pos);
                pos++;
            }
            printf(" ");
            pos = saved;
        } else if (pos == sen){
            while(*pos != ' '){
                printf("%c", *pos);
                pos++;
            }
            break;
        } else {
            pos--;
        }
    }

    printf("%c", end);


    return 0;
}