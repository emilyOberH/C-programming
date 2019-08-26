#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int right = 0;
    int ans;
    float score;
    int store1[10];
    int store2[10];

    for(int i=0; i<10; ++i){
        int num1 = rand()%(10)+1;
        int num2 = rand()%(10)+1;
        for(int j=0; j<i; ++j){
            if(store1[j]==num1&&store2[j]==num2){
                num1 = rand()%(10)+1;
                num2 = rand()%(10)+1;
                j = 0;
            }
        }
        store1[i] = num1;
        store2[i] = num2;

        printf("\n%d * %d = ", num1, num2);
        scanf("%d", &ans);
        if(ans==num1*num2){
            ++right;
        }
    }
    switch(right){
    case 10:
        score = 5;
        break;
    case 9:
        score = 4.5;
        break;
    case 8:
        score = 4;
        break;
    case 7:
        score = 3.5;
        break;
    case 6:
        score = 3;
        break;
    default:
        score = 2;
        break;
    }
    printf("\n%d out of 10 correct answers given. Score: %g", right, score);

    return 0;
}
