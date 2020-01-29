#include <stdio.h>

#define NUM_ENTRY 5

int main(void){

    int nums[NUM_ENTRY][NUM_ENTRY] = {0}, sum = 0;

    for(int i = 0; i < NUM_ENTRY; i++){
        printf("Enter row %d: ", i+1);
        for(int ix = 0; ix < NUM_ENTRY; ix++){
            scanf(" %d", &nums[i][ix]);
        }
    }

    printf("\n\nRow totals: ");
    for(int i = 0; i < NUM_ENTRY; i++){
        for(int ix = 0; ix < NUM_ENTRY; ix++){
            sum += nums[i][ix];
        }
        printf("%d ", sum);
        sum = 0;
    }

    printf("\nColumn totals: ");
    for(int i = 0; i < NUM_ENTRY; i++){
        for(int ix = 0; ix < NUM_ENTRY; ix++){
            sum += nums[ix][i];
        }
        printf("%d ", sum);
        sum = 0;
    }



    return 0;
}