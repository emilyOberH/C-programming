#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generateArray(int *, int, int, int);
void displayArray(int *, int);
void reverseArray(int *, int);
void swapIntegers(int *, int *);

int main(){
    int n, a, b;
    printf("Enter length of array: ");
    scanf("%d", &n);
    printf("Enter starting point for the range of integers in array: ");
    scanf("%d", &a);
    printf("Enter end point for the range of integers in array: ");
    scanf("%d", &b);
    if(b<a){
        int temp = a;
        a = b;
        b = temp;
    }

    int *A=(int*)malloc(n*sizeof(int));
    generateArray(A, n, a, b);
    displayArray(A, n);
    reverseArray(A, n);
    displayArray(A, n);

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

    printf("\nArray: ");
    while(walker<stopper){
        printf("%d ",*walker);
        ++walker;
    }
    printf("\n");
}
void reverseArray(int *A, int n){
    int *walker = A;
    int *stopper = A+n;
    int *counter = A+n-1;

    printf("\nArray reversed: ");
    while(walker<stopper){
        if(counter<=walker){
            break;
        }else{
            swapIntegers(&(*walker),&(*counter));
        }
        --counter;
        ++walker;
    }
}

void swapIntegers(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
