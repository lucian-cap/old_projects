#include <stdio.h>

int main(void){

    int square[99][99], size = 0, row = 0, col, count = 1;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");

    while(size%2 != 1){
        printf("Enter size of magic square: ");
        scanf("%d", &size);
    }

    col = size/2;

    for (int i = 0; i < size; i++){
        for (int ix = 0; ix < size; ix++){
            square[i][ix] = 0;
        }
    }

    while(count <= size*size){
        if(square[row][col] == 0){
            square[row][col] = count;
            row--;
            col++;
            count++;
        } else{
            row++;
        }

        if (row == -1){
            row = size - 1;
        }
        if (col == size){
            col = 0;
        }
    }

    for (int i = 0; i < size; i++){
        for (int ix = 0; ix < size; ix++){
            printf("%3d", square[i][ix]);
        }
        printf("\n");
    }

    return 0;
}