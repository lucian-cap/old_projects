#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p4_line.h"

#define MAX_LINE_LEN 60

//char line[MAX_LINE_LEN+1];
int line_len = 0, num_words = 0;
struct word {
    char word[MAX_WORD_LEN+2];
    struct word *next;
};

struct word *line = NULL;

void clear_line(void){
    
    struct word *cur, *next;
    for(cur = line; cur != NULL; cur = next){
            next = cur->next;
            free(cur);
        }
    line_len = 0;
    num_words = 0;
    line = NULL;
}

void add_word(const char *word){
    struct word *new_word = malloc(sizeof(struct word)), *cur = line;
    strcpy(new_word->word, word);
    new_word->next = NULL;

    if(line == NULL){
        line = new_word;
    } else {
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new_word;
    }

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void){
    return MAX_LINE_LEN - line_len;
}

void write_line(void){
    int extra_spaces, spaces_to_insert, i, j;
    struct word *cur = line;

    extra_spaces = MAX_LINE_LEN - line_len;

    while(cur != NULL){
        printf("%s", cur->word);

        if(num_words > 1){

            spaces_to_insert = extra_spaces / (num_words - 1);
            for(j = 1; j <= spaces_to_insert + 1; j++){
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
            num_words--;
        }

        cur = cur->next;
    }
    putchar('\n');
}

void flush_line(void){
    struct word *cur = line;

    if(line_len > 0){
        while(cur != NULL){
            printf("%s ", cur->word);
            cur = cur->next;
        }
    }
}