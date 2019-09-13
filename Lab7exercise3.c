#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readArray(int *, int);
void largest(int *, int);
void smallest(int *, int);
void countPositive(int *, int, bool (*)(int));
void averagePositive(int *, int, bool (*)(int));
bool isPos(int);

int main(){
    int n;
    printf("\nEnter length of array: ");
    scanf("%d", &n);

    int *A = (int*)malloc(n*sizeof(int));
    readArray(A, n);
    largest(A, n);
    smallest(A, n);
    countPositive(A, n, isPos);
    averagePositive(A, n, isPos);

    printf("\n");
    free(A);
    return 0;
}

void readArray(int *A, int n){
    int *walker = A;
    int *stopper = A+n;

    while(walker<stopper){
        printf("\n#%d: ", (int)(walker-A)+1 );
        scanf("%d", &(*walker));
        ++walker;
    }
}

void largest(int *A, int n){
    int *walker = A;
    int *stopper = A+n;

    int largest = *walker;
    while(walker<stopper){
        if((*walker)>largest){
            largest=(*walker);
        }
        ++walker;
    }

    printf("\nLargest number in array is: %d", largest);
}

void smallest(int *A, int n){
    int *walker = A;
    int *stopper = A+n;

    int smallest = *walker;
    while(walker<stopper){
        if((*walker)<smallest){
            smallest=(*walker);
        }
        ++walker;
    }

    printf("\nSmallest number in array is: %d", smallest);
}

void countPositive(int *A, int n, bool (*isPos) (int)){
    int *walker = A;
    int *stopper = A+n;

    int pos = 0;
    while(walker<stopper){
        if(isPos(*walker)){
            ++pos;
        }
        ++walker;
    }

    printf("\nNumber of positive values in array greater than 0: %d", pos);
}

void averagePositive(int *A, int n, bool (*isPos) (int)){
    int *walker = A;
    int *stopper = A+n;

    int pos = 0;
    int counter = 0;
    while(walker<stopper){
        if(isPos(*walker)){
            pos+=(*walker);
            ++counter;
        }
        ++walker;
    }
    if(counter==0){
        counter=1;
    }

    printf("\nAverage of positive non-zero values in array: %g", pos/(double)counter);
}

bool isPos(int a){
    if(a>0){
        return true;
    }else{
        return false;
    }
}
