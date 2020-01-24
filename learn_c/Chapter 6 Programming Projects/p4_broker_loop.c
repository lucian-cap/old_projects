#include <stdio.h>

int main(void){

    float comm, value;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    while (value != 0.00f){
        if (value < 2500.00f){
            comm = 30 + .017f * value;
            if (comm < 39.00f){
                comm = 39.00f;
            }
        } else if (value < 6250.00f){
            comm = 56 + .0066f * value;
        } else if (value < 20000.00f){
            comm = 76 + .034f * value;
        } else if (value < 50000.00f){
            comm = 100 + .0022f * value;
        } else if (value < 500000.00f){
            comm = 155 + .0011f * value;
        } else {
            comm = 255 + .0009f * value;
        }

        printf("Commission: $%.2f\n\n", comm);

        printf("Enter value of trade: ");
        scanf("%f", &value);
        
    }


    return 0;
}