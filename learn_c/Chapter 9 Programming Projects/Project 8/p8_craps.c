#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void){

    srand((unsigned) time(NULL));

    int wins = 0, losses = 0;
    char play = 'Y';

    while (toupper(play) == 'Y'){
        if(play_game() == true){
            printf("You win!\n");
            wins++;
        } else {
            printf("You lose!\n");
            losses++;
        }
        printf("Play again? ");
        scanf(" %c", &play);
    }

    printf("Wins: %d\tLosses: %d", wins, losses);
    return 0;
}

bool play_game(void){
    int roll, point = 0;
    bool r_val;

    point = roll_dice();

    if (point == 7 || point == 11){
        printf("You rolled: %d\n", point);
        r_val = true;
    } else if (point == 2 || point == 3 || point == 12){
        printf("You rolled: %d\n", point);
        r_val = false;
    } else{
        printf("You rolled: %d\n", point);
        printf("Your point is %d\n", point);

        while (true){
            roll = roll_dice(); 
            printf("You rolled: %d\n", roll);

            if(roll == point){
                r_val = true;
                break;
            } else if (roll == 7){
                r_val = false;
                break;
            } else{
                continue;
            }
        }
    }

    return r_val;

}

int roll_dice(void){
    int d1, d2;

    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;

    return d1+d2;
}