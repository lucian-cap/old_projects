#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void){

    int word1[26], word2[26];

    for(int i = 0; i < 26; i++){
        word1[i] = 0;
        word2[i] = 0;
    }

    printf("Enter first word: ");
    read_word(word1);

    printf("Enter second word: ");
    read_word(word2);

    if(equal_array(word1, word2)){
        printf("These two words are anagrams.");
    } else {
        printf("These words are not anagrams.");
    }

    return 0;
}

void read_word(int counts[26]){
    char ch;
    
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            counts[tolower(ch) - 'a']++;
        }
    }
}

bool equal_array(int counts1[26], int counts2[26]){

    for(int i = 0; i < 26; i++){
        if(counts1[i] != counts2[i]){
            return false;
        }
    }

    return true;
}