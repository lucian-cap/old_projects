#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_LET 26
#define MAX_LEN 20

bool are_anagrams(const char *word1, const char *word2);

int main (void){

    char word1[MAX_LEN+1], word2[MAX_LEN+1];

    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);

    if(are_anagrams(word1, word2)){
        printf("The words are anagrams.");
    } else {
        printf("The words are not anagrams.");
    }

    return 0;
}

bool are_anagrams(const char *word1, const char *word2){
    int letters[NUM_LET];
    bool r_val = true;

    for(int i = 0; i < NUM_LET; i++){
        letters[i] = 0;
    }

    while(*word1 != '\n' && *word1 != '\0' && isalpha(*word1)){
        letters[tolower(*word1++)-'a']++;
    }
    while(*word2 != '\n' && *word2 != '\0' && isalpha(*word2)){
        letters[tolower(*word2++)-'a']--;
    }

    for(int i = 0; i < NUM_LET; i++){
        if(letters[i] != 0){
            r_val = false;
            break;
        }
    }

    return r_val;
}