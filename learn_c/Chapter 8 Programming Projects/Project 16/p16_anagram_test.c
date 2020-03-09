#include <stdio.h>
#include <ctype.h>

int main(void){

    int word[26], check = 0;
    char ch;

    for(int i = 0; i < 26; i++){
        word[i] = 0;
    }

    printf("Enter first word: ");
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            word[tolower(ch) - 'a']++;
        }
    }

    printf("Enter second word: ");
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            word[tolower(ch) - 'a']--;
        }
    }

    for(int i = 0; i < 26; i++){
        if (word[i] != 0){
            check++;
        }
    }

    if (check != 0){
        printf("These words are not anagrams.");
    } else {
        printf("These words are anagrams.");
    }

    return 0;
}