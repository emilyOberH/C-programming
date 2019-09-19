#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generateArray(int *, int, int, int);
void displayArray(int *, int);
int bubbleSort(int *, int);

int main(){
    srand(time(NULL));
    int n, a, b;
    int *A = (int*)malloc(n*sizeof(int));
    printf("\nHow may integers? ");
    scanf("%d", &n);
    printf("\nEnter starting point of the range of numbers: ");
    scanf("%d", &a);
    printf("\nEnter starting point of the range of numbers: ");
    scanf("%d", &b);
    if(a>b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    generateArray(A, n, a, b);
    printf("\nArray before bubble-sort:\t");
    displayArray(A, n);
    printf("\nArray after bubble-sort:\t");
    int num = 1;
    do{
        num = bubbleSort(A, n);
    }while(num!=0);
    displayArray(A, n);

    free(A);
    return 0;
}

void generateArray(int *A, int n, int a, int b){
    int *walker = A;
    int *stopper = A+n;
    while(walker<stopper){
        *walker = rand()%(b-a+1)+a;
        ++walker;
    }
}

void displayArray(int *A, int n){
    int *walker = A;
    int *stopper = A+n;
    while(walker<stopper){
        printf("%d ", *walker);
        ++walker;
    }
}

int bubbleSort(int *A, int n){
    int *walker = A;
    int *stopper = A+(n-1);
    int counter = 0;
    while(walker<stopper){
        int *walkerA = walker+1;
        if(*walker>*walkerA){
            ++counter;
            int tmp = *walker;
            *walker = *walkerA;
            *walkerA = tmp;
        }
        ++walker;
    }
    return counter;
}
