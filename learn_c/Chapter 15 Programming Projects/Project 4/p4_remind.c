#include <stdio.h>
#include <string.h>
#include "p4_readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60

int main(void){

    char reminders[MAX_REMIND][MSG_LEN+9];
    char date_str[9], msg_str[MSG_LEN+1];
    int num_remind = 0, month, day, time, i, j;

    while(1){
        if(num_remind == MAX_REMIND){
            printf("---No space left.---");
            break;
        }

        printf("Enter reminder (in month/day hour message format): ");
        scanf("%d/%d %d", &month, &day, &time);

        if(month == 0 || day == 0){
            break;
        } else if (month < 1 || month > 12 || day < 1 || day > 31){
            continue;
        }

        sprintf(date_str, "%02d/%02d %02d", month, day, time);
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++){
            if(strcmp(date_str, reminders[i]) < 0){
                break;
            }
        }

        for(j = num_remind; j > i; j--){
            strcpy(reminders[j], reminders[j-1]);
        }
        strcpy(reminders[i], date_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for(i = 0; i < num_remind; i++){
        printf(" %s\n", reminders[i]);
    }

    return 0;
}
