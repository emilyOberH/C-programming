#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void getData(int *, int);
void displayData(int *, int);
bool isPosEven(int);
void averageIf(int *, int, bool (*) (int));
void countIf(int *A, int n, bool (*func) (int));

int main(){
    int n = 0;
    printf("\nHow many integers in array?");
    scanf("%d", &n);
    int *A = (int*)malloc(n*sizeof(int));
    getData(A, n);
    displayData(A, n);
    averageIf(A, n, isPosEven);
    countIf(A, n, isPosEven);
    printf("\n");

    free(A);
    return 0;
}

void getData(int *A, int n){
    int *walker = A;
    int *stopper = A+n;
    while(walker<stopper){
        printf("\nEnter integer #%d: ", (int)(walker-A)+1);
        scanf("%d", &(*walker));
        ++walker;
    }
}

void displayData(int *A, int n){
    int *walker = A;
    int *stopper = A+n;
    printf("\nArray: ");
    while(walker<stopper){
        printf("%d\t", (*walker));
        ++walker;
    }
}

void averageIf(int *A, int n, bool (*func) (int)){
    int *walker = A;
    int *stopper = A+n;
    int sum = 0;
    double counter = 0.0;
    while(walker<stopper){
        if(func(*walker)){
            sum+=*walker;
            ++counter;
        }
        ++walker;
    }
    if(counter==0){
        counter=1;
    }
    printf("\nSum of all positive and even elements in array: ");
    printf("%d", sum);
    printf("\nAverage of all positive and even elements in array: ");
    printf("%g", ((double)sum)/counter);
}

void countIf(int *A, int n, bool (*func) (int)){
    int *walker = A;
    int *stopper = A+n;
    int counter = 0;
    printf("\nNumber of all positive and even elements in array: ");
    while(walker<stopper){
        if(func(*walker)){
            ++counter;
        }
        ++walker;
    }
    if(counter==0){
        counter=1;
    }
    printf("%d", counter);
}

bool isPosEven(int n){
    if(n>0&&n%2==0){
        return true;
    }else{
        return false;
    }
}

