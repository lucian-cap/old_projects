#include <stdio.h>

void create_magic_square(int n, int magic_square[99][99]);
void print_magic_square(int n, int magic_square[99][99]);

int main(void){

    int square[99][99], size = 0;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");

    while(size%2 != 1){
        printf("Enter size of magic square: ");
        scanf("%d", &size);
    }

    create_magic_square(size, square);
    print_magic_square(size, square);

    return 0;
}

void create_magic_square(int n, int magic_square[99][99]){
    int row = 0, col, count = 1;

    col = n/2;
    for (int i = 0; i < n; i++){
        for (int ix = 0; ix < n; ix++){
            magic_square[i][ix] = 0;
        }
    }

    while(count <= n*n){
        if(magic_square[row][col] == 0){
            magic_square[row][col] = count;
            row--;
            col++;
            count++;
        } else{
            row++;
        }

        if (row == -1){
            row = n - 1;
        }
        if (col == n){
            col = 0;
        }
    }
}

void print_magic_square(int n, int magic_square[99][99]){
    for (int i = 0; i < n; i++){
        for (int ix = 0; ix < n; ix++){
            printf("%3d", magic_square[i][ix]);
        }
        printf("\n");
    }
}