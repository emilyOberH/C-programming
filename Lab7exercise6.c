#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generateArray(int *, int, int, int);
void displayArray(int *, int);
int qSort(int *, int);
int compare(const void *, const void *);

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
    qsort(A, n, sizeof(int), compare);
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

int compare(const void *first, const void *second){
    int *a = (int*)first;
    int *b = (int*)second;

    if(*a>*b){
        return +1;
    }else if(*a<*b){
        return -1;
    }else{
        return 0;
    }
}
