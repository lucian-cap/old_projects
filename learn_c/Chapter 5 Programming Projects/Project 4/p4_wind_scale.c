#include <stdio.h>

int main(void){

    float speed;

    printf("Enter the wind speed (in knots): ");
    scanf("%f", &speed);

    if (speed < 1.00f){
        printf("Wind at that speed is considered to be 'Calm'.");
    } else if (speed < 3.00f){
        printf("Wind at that speed is considered to be 'Light air'.");
    } else if (speed < 27.00f){
        printf("Wind at that speed is considered to be a 'Breeze'.");
    } else if (speed < 47.00f){
        printf("Wind at that speed is considered to be a 'Gale'.");
    } else if (speed < 63.00f){
        printf("Wind at that speed is considered to be a 'Storm'.");
    } else {
        printf("Wind at that speed is considered to be a 'Hurricane'.");
    }

    return 0;
}