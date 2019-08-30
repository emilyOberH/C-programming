#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    int n;
    printf("\nEnter dimension of square matrix: ");
    scanf("%d", &n);

    int **A = (int**)malloc(n*sizeof(int*));
    int **walker = A;
    int **stopper = A+n;
    while (walker<stopper){
        *walker = (int*)malloc(n*sizeof(int));
        ++walker;
    }
    walker = A;

    while (walker<stopper){
        int *walkerI = *walker;
        int *stopperI = *walker+n;
        while (walkerI<stopperI){
            *walkerI = rand()%100;
            ++walkerI;
        }
        ++walker;
    }
    walker = A;

    while (walker<stopper){
        int *walkerI = *walker;
        int *stopperI = *walker+n;
        while (walkerI<stopperI){
            printf("%d\t", *walkerI);
            ++walkerI;
        }
        printf("\n");
        ++walker;
    }
    walker = A;

    int sum = 0;
    int diag = 0;
    printf("\nSum of elements in diagonal: ");
    while (walker<stopper){
        int *walkerI = *walker;
        int *stopperI = *walker+n;
        while (walkerI<stopperI){
            int index = (int)(walkerI-*walker);
            if(index==diag){
                sum+=*walkerI;
                ++diag;
                break;
            }
            ++walkerI;
        }
        ++walker;
    }
    printf("%d", sum);
    walker = A;


    sum = 0;
    diag = 0;
    printf("\nSum of elements below diagonal: ");
    while (walker<stopper){
        int *walkerI = *walker;
        int *stopperI = *walker+n;
        while (walkerI<stopperI){
            int index = (int)(walkerI-*walker);
            if(index<diag){
                sum+=*walkerI;
            }
            ++walkerI;
            if(index==diag){
                ++diag;
                break;
            }
        }
        ++walker;
    }
    printf("%d", sum);
    walker = A;


    sum = 0;
    diag = 0;
    printf("\nSum of elements above diagonal: ");
    while (walker<stopper){
        int *walkerI = *walker;
        int *stopperI = *walker+n;
        while (walkerI<stopperI){
            int index = (int)(walkerI-*walker);
            if(index>diag){
                sum+=*walkerI;
            }
            if(index==n-1){
                ++diag;
            }
            ++walkerI;
        }
        ++walker;
    }
    printf("%d", sum);

    free(A);
    return 0;
}
