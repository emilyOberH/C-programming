#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fillArray(int **, int, int, int, int);
void displayArray(int **, int, int);
void posValInRows(int **, int, int);
void posValInCol(int **, int, int);

int main(){
    int n = 4, m = 5;
    int a = -5, b =5;

    srand(time(NULL));
    int **A = (int**)malloc(n*sizeof(int *));
    fillArray(A, n, m, a, b);
    displayArray(A, n, m);
    posValInRows(A, n, m);
    posValInCol(A, n, m);

    free(A);
    return 0;
}

void fillArray(int **A, int n, int m, int a, int b){
    int **walker = A;
    int **stopper = A+n;
    int count = 0;

    while(walker<stopper){
        *walker = (int*)malloc(m*sizeof(int));
        ++(walker);
    }
    walker = A;

    while(walker<stopper){
        int *walkerB = *walker;
        int *stopperB = (*walker)+m;
        while(walkerB<stopperB){
            *walkerB = rand()%(b+1-a)+a;
            ++count;
            ++walkerB;
        }
        ++walker;
    }
}

void displayArray(int **A, int n, int m){
    int **walker = A;
    int **stopper = A+n;

    while(walker<stopper){
        int *walkerB = *walker;
        int *stopperB = *walker+m;
        while(walkerB<stopperB){
            printf("%d\t", *walkerB);
            ++walkerB;
        }
        printf("\n");
        ++walker;
    }
}

void posValInRows(int **A, int n, int m){
    int **walker = A;
    int **stopper = A+n;
    int counter = 0;

    printf("\nPositive values in rows:\n");
    while(walker<stopper){
        int *walkerB = *walker;
        int *stopperB = *walker+m;
        while(walkerB<stopperB){
            if((*walkerB)>0){
                ++counter;
            }
            ++walkerB;
        }
        printf("%d\t", counter);
        counter = 0;
        ++walker;
    }
}

void posValInCol(int **A, int n, int m){
    int **walker = A;
    int **stopper = A+n;
    int counter = 0;
    int index = 0;

    printf("\nPositive values in columns:\n");
    for(int i=0; i<m; ++i){
        walker = A;
        while(walker<stopper){
            int *walkerB = *walker;
                if(walkerB[index]>0){
                    ++counter;
                }
            ++walker;
        }
            printf("%d\t", counter);
            counter = 0;
            ++index;
    }
}
