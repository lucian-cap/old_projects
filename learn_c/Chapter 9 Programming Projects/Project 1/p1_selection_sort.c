#include <stdio.h>

#define SIZE 100

void selection_sort(int a[], int loc);

int main(void){

    int a[SIZE], num;

    printf("Enter the number of integers to be entered: ");
    scanf("%d", &num);

    printf("Enter the list of integers: ");
    for(int i = 0; i < num; i++){
        scanf(" %d", &a[i]);
    }

    selection_sort(a, num-1);

    printf("Sorted list of integers: ");
    for(int i = 0; i < num; i++){
        printf(" %d", a[i]);
    }

    return 0;
}

void selection_sort(int a[], int loc){
    int val = a[0], spot = 0;

    if (loc > 0){
        for(int i = 0; i <= loc; i++){
            if (val < a[i]){
                val = a[i];
                spot = i;
            }
        }
        a[spot] = a[loc];
        a[loc] = val;
        loc--;
        selection_sort(a, loc);

    }
}