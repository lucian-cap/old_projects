#include <stdio.h>

#define N 10

void max_min(int nums[], int *max, int *min);

int main(void){

    int nums[N], max, min;

    printf("Enter %d numbers: ", N);
    for(int i = 0; i < N; i++){
        scanf(" %d", &nums[i]);
    }

    max_min(nums, &max, &min);
    printf("Largest: %d\nSmallest: %d", max, min);

    return 0;
}

void max_min(int nums[], int *max, int *min){
    int *pos = nums;
    *max = *min = *pos;

    while(pos < &nums[N]){
        if(*pos > *max){
            *max = *pos;
        }
        else if(*pos < *min){
            *min = *pos;
        }
        pos++;
    }
}