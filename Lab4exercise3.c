#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(){
    int n=0;
    while(n<2){
        printf("\nEnter number greater than 1: ");
        scanf("%d", &n);
    }
    printf("\nPrime numbers less than %d: ", n);

    bool *A=(bool*)malloc((n)*sizeof(bool));
    bool *walker = A;
    bool *stopper = A+n;
    while(walker<stopper){
        *walker = true;
        ++walker;
    }
    walker = A;

    for(int i=2; i<n; ++i){
        if(A[i]==true){
            int counter = 1;
            int num=i+i;
            for(int j=num; j<n; j+=i){
                //printf("%d ", j);
                A[j]=false;
                ++counter;
            }
        }
    }
    for(int i=2; i<n; ++i){
        if(A[i]==true){
            printf("%d ",i );
        }
    }

    /*while(walker<stopper){
        printf("%d ",((int)walker)-((int)A) );
        ++walker;
    }*/

    free(A);
    return 0;
}
