#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 20
#define MAX_LEN 20

void read_line(char *word, int len);
int compare_words(const void *p, const void *q);

int main(void){

    char *words[MAX_WORDS], new_word[MAX_LEN+1];
    int num_words = 0, i;

    while(1){
        if(num_words == MAX_WORDS){
            printf("--- No space left ---\n");
            break;
        } else {
            printf("Enter word: ");
            read_line(new_word, MAX_LEN);

            if(new_word[0] == '\0'){
                break;
            }

            for(i = 0; i < num_words; i++){
                if(strcmp(new_word, words[i]) < 0){
                    break;
                }
            }
            for(int j = num_words; j > i; j--){
                words[j] = words[j-1];
            }

            words[i] = malloc(strlen(new_word));
            if(words[i] == NULL){
                printf("--- No space left ---\n");
                break;
            } else{
                strcpy(words[i], new_word);
            }
            num_words++;
        }
    }

    //qsort(words, num_words, sizeof(char *), compare_words);

    printf("In sorted order: ");
    for(int i = 0; i < num_words; i++){
        printf("%s ", words[i]);
    }

    return 0;
}

void read_line(char *word, int len){
    int i = 0;
    char ch;

    while((ch = getchar()) != '\n'){
        if(i < len){
            *(word+i) = ch;
            i++;
        }
    }
    *(word+i) = '\0';
}

// int compare_words(const void *p, const void *q){
//     return strcmp((char *) p, (char *) q);
// }