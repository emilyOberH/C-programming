#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void generateArray(int *, int, int, int);
void displayArray(int *, int);
void countIfEven(int *, int, bool(*)(int), int *);
void copyIfEven(int *, int, bool(*)(int), int *);
bool isEven(int);

int main(){
    srand(time(NULL));
    int size;
    int n = 10;
    int a = -25;
    int b = 25;
    int *A = (int*)malloc(n*sizeof(int));

    generateArray(A, n, a, b);
    printf("Array of %d numbers:\n", n);
    displayArray(A, n);
    countIfEven(A, n, isEven, &size);
    copyIfEven(A, n, isEven, &size);

    free(A);
    return 0;
}

void generateArray(int *A, int n, int a, int b){
    int *walker = A;
    int *stopper = A+n;

    while(walker<stopper){
        *walker = rand()%(b+1-a)+a;
        ++walker;
    }
}

void displayArray(int *A, int n){
    int *walker = A;
    int *stopper = A+n;

    while(walker<stopper){
        printf("%d ",*walker);
        ++walker;
    }
}

void countIfEven(int *A, int n, bool(*func)(int), int* size){
    int counter = 0;
    int *walker = A;
    int *stopper = A+n;

    while(walker<stopper){
        if(func(*walker)){
            ++counter;
        }
        ++walker;
    }
    printf("\nNumber of even values in array is: %d\n", counter);
    *size = counter;
}

void copyIfEven(int *A, int n, bool (*func)(int), int* size){
    int *walker = A;
    int *stopper = A+n;
    int *B = (int*)malloc((*size)*sizeof(int));
    int *walkerB = B;

    while(walker<stopper){
        if(func(*walker)){
           *walkerB = *walker;
            ++walkerB;
        }
        ++walker;
    }
    printf("\nArray of %d even numbers:\n", (*size));
    displayArray(B, *size);
    printf("\n");
}

bool isEven(int num){
    if(num%2==0){
        return true;
    }else{
        return false;
    }
}
