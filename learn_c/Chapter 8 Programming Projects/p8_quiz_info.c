#include <stdio.h>

#define NUM_ENTRY 5

int main(void){

    double scores[NUM_ENTRY][NUM_ENTRY] = {0}, total = 0.00f, max = 0.00f, min = 1000.00f, value = 0.00f;


    for (int i = 0; i < NUM_ENTRY; i++){
        printf("Enter scores for student %d: ", i+1);
        for(int ix = 0; ix < NUM_ENTRY; ix++){
            scanf("%lf", &scores[i][ix]);
        }
    }

    printf("\n\nStudent\tTotal\tAverage\n");
    for(int i = 0; i < NUM_ENTRY; i++){
        for(int ix = 0; ix < NUM_ENTRY; ix++){
            total += scores[i][ix];
        }
        printf("%3d\t%5.2lf\t%5.2lf\n", i+1, total, total/NUM_ENTRY);
        total = 0.00f;
    }

    printf("\n\nQuiz\tAverage\tMax\tMin\n");
    for(int i = 0; i < NUM_ENTRY; i++){
        for (int ix = 0; ix < NUM_ENTRY; ix++){
            value = scores[ix][i];
            
            total += value;

            if (value < min){
                min = value;
            }
            if (value > max){
                max = value;
            }
        }
        printf("%3d\t%5.2lf\t%5.2lf\t%5.2lf\n", i+1, total/NUM_ENTRY, max, min);
        total = 0.00f, min = 1000.00f;
        max = 0.00f;
    }

    return 0;
}