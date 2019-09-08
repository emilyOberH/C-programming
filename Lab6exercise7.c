#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayTriangle(int, char);

int main(){
    int r=-1;
    char c;
    while(r<0){
        printf("\nEnter height of triangle: ");
        scanf("%d", &r);
    }
    fflush(stdin);
    printf("\nEnter character to fill the triangle with: ");
    scanf("%c", &c);

    displayTriangle(r, c);
    return 0;
}

void displayTriangle(int r, char c){
    for(int i=0; i<=r; ++i){
        for(int j=0; j<i; ++j){
            printf("%c", c);
        }
        printf("\n");
    }
}
