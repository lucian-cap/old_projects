#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 100

bool is_palindrome(const char *message);

int main(void){

    char message[MAX_LEN+1];

    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);

    if(is_palindrome(message)){
        printf("Palindrome.");
    } else {
        printf("Not a palindrome.");
    }

    return 0;
}

bool is_palindrome(const char *message){
    bool r_val = true;
    const char *end = message;

    while(*end != '\n' && *end != '\0'){
        end++;
    }
    end--;

    while(message <= end){
        if(!isalpha(*message)){
            message++;
            continue;
        } else if(!isalpha(*end)){
            end--;
            continue;
        } else if(tolower(*message) != tolower(*end)){
            r_val = false;
            break;
        } else{
            message++;
            end--;
        }
    }
    return r_val;
}