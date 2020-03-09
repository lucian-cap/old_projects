#include <stdio.h>
#include <ctype.h>

int main(void){

    int scores[26] = {[0] = 1, [1] = 3, [2] = 3, [3] = 2, [4] = 1,
                      [5] = 4, [6] = 2, [7] = 4, [8] = 1, [9] = 8,
                      [10] = 5, [11] = 1, [12] = 3, [13] = 1, [14] = 1,
                      [15] = 3, [16] = 10, [17] = 1, [18] = 1, [19] = 1,
                      [20] = 1, [21] = 4, [22] = 4, [23] = 8, [24] = 4,
                      [25] = 10}, sum = 0;
    char ch;

    printf("Enter a word: ");

    while ((ch = toupper(getchar())) != '\n'){
        if(ch - 'A' > 25 || ch - 'A' < 0){
            printf("An invalid character was found. This is not a SCRABBLE word.");
            sum = -1;
            break;
        } else {
            sum += scores[ch - 'A'];
        }
    }

    if (sum != -1){
        printf("Scrabble value: %d", sum);
    }




    return 0;
}