#include <stdio.h>

int main(void){

    int num_share;
    float cost_share, og_commission, rival_commission, value_trade;

    printf("Enter the number of shares: ");
    scanf("%d", &num_share);

    printf("Enter the cost per share: ");
    scanf("%d", &cost_share);

    value_trade = num_share*cost_share;

    if (value_trade < 2500.00f){
        og_commission = 30 + .017f * value_trade;
        if (og_commission < 39){
            og_commission = 39.00f;
        }
    } else if (value_trade < 6250.00f){
        og_commission = 56 + .0066f * value_trade;
    } else if (value_trade < 20000.00f){
        og_commission = 76 + .0034f * value_trade;
    } else if (value_trade < 50000.00f){
        og_commission = 100 + .0022f * value_trade;
    } else if (value_trade < 500000.00f){
        og_commission = 155 + .0011f * value_trade;
    } else {
        og_commission = 255 + .0009f * value_trade;
    }

    if (num_share < 2000){
        rival_commission = 33 + .03f * num_share;
    } else {
        rival_commission = 33 + .02f * num_share;
    }

    printf("The original brokers commission is %.2f.", og_commission);
    printf("The rival brokers commission is %.2f.", rival_commission);

    return 0;
}