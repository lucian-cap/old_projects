#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int main(void){

    char path[SIZE][SIZE] = {'.'}, let = 'A';
    int dir, row = 0, col = 0, left_b = 0, top_b = 0, right_b = 0, bottom_b = 0;

    for (int i = 0; i < SIZE; i++){
        for (int ix = 0; ix < SIZE; ix++){
            path[i][ix] = '.';
        }
    }

    path[row][col] = let;
    let++;

    srand((unsigned) time(NULL));

    while(1){

        if(top_b + right_b + bottom_b + left_b == 4 || let > 'Z'){
            break;
        } else {

            dir = rand() % 4;

            if (dir == 0){
                if (row - 1 < 0){
                    top_b = 1;
                    continue;
                } else if (path[row-1][col] != '.'){
                    top_b = 1;
                    continue;
                } else {
                    row -= 1;
                }
            } else if (dir == 1){
                if (col+1 > 9){
                    right_b = 1;
                    continue;
                } else if (path[row][col+1] != '.'){
                    right_b = 1;
                    continue;
                } else {
                    col += 1;
                }
            } else if (dir == 2){
                if (row+1 > 9){
                    bottom_b = 1;
                    continue;
                } else if (path[row+1][col] != '.'){
                    bottom_b = 1;
                    continue;
                } else {
                    row += 1;
                }
            } else {
                if (col-1 < 0){
                    left_b = 1;
                    continue;
                } else if (path[row][col-1] != '.'){
                    left_b = 1;
                    continue;
                } else {
                    col -= 1;
                }
            }

            path[row][col] = let;
            let++;
            top_b = 0, right_b = 0; bottom_b = 0, left_b = 0;
        
        }
        
    }

    for (int i = 0; i < SIZE; i++){
        for (int ix = 0; ix < SIZE; ix++){
            printf(" %c", path[i][ix]);
        }
        printf("\n");
    }

    return 0;
}