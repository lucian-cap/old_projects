#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char ch, line[11];
    int offset = 0;

    if(argc != 2){
        printf("This program requires a SINGLE input file.\n");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "rb")) == NULL){
        printf("File %s could not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n-----  --------------------------------- ---------\n");
    while(1){
        printf("%5d  ", offset);
        for(int i = 0; i < 10; i++){
            ch = getc(fp);
            if(ch == EOF){
                break;
            }

            if(!isprint(ch)){
                ch = '.';
            }
            printf("%X ", ch);
            line[i] = ch;
        }
        printf(" %10s\n", line);
        for(int i = 0; i < 10; i++){
            line[i] = '\0';
        }

        offset+=10;
        if(ch == EOF){
            break;
        }
    }

    return 0;
}