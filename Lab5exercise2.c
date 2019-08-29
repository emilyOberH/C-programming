#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    printf("\nFirst array: ");
    printf("\nSize: ");
    scanf("%d", &n);

    printf("\nFirst array: ");
    printf("\nSize: ");
    scanf("%d", &m);

    int *A = (int*)malloc(n*sizeof(int));
    int *walkerA = A;
    int *stopperA = A+n;
    int *B = (int*)malloc(m*sizeof(int));
    int *walkerB = B;
    int *stopperB = B+m;

    printf("\nEnter numbers of first array: ");
    while(walkerA<stopperA){
        printf("\n#%d: ", (int)(walkerA-A)+1);
        scanf("%d", &*walkerA);
        ++walkerA;
    }
    printf("\nEnter numbers of second array: ");
    while(walkerB<stopperB){
        printf("\n#%d: ", (int)(walkerB-B)+1);
        scanf("%d", &*walkerB);
        ++walkerB;
    }
    walkerA = A;
    walkerB = B;

    printf("*\t");
    while(walkerB<stopperB){
        printf("%d\t", *walkerB);
        ++walkerB;
    }
    walkerB = B;
    while(walkerA<stopperA){
        printf("\n%d\t", *walkerA);
        walkerB = B;
        while(walkerB<stopperB){
            printf("%d\t", (*walkerB)*(*walkerA));
            ++walkerB;
        }
        ++walkerA;
    }
    free(A);
    free(B);
    return 0;
}
