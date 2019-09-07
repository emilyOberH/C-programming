#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayTriangle(int);

int main(){
    int r=-1;
    while(r<0){
        printf("\nEnter height of triangle: ");
        scanf("%d", &r);
    }

    displayTriangle(r);
    return 0;
}

void displayTriangle(int r){
    for(int i=0; i<=r; ++i){
        for(int j=0; j<i; ++j){
            printf("*");
        }
        printf("\n");
    }
}
