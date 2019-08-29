#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    srand(time(NULL));
    int n, m;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    printf("\nEnter number of columns: ");
    scanf("%d", &m);

    int **A=(int**)malloc(n*sizeof(int*));
    int **walker = A;
    int **stopper = A+n;
    while(walker<stopper){
        *walker = (int*)malloc(m*sizeof(int));
        ++walker;
    }
    walker = A;
    while(walker<stopper){
        int *walker2 = *walker;
        int *stopper2 = *walker+m;
        while(walker2<stopper2){
            *walker2 = rand()%100;
            ++walker2;
        }
        ++walker;
    }

    walker = A;
    int sum = **A; //find row with greatest sum
    int rowEven[n];    //find rows with at least 2 even numbers
    for(int i=0; i<n; ++i){
        rowEven[i]=0;
    }
    while(walker<stopper){
        int *walker2 = *walker;
        int *stopper2 = *walker+m;
        int sumR = 0;
        while(walker2<stopper2){
            sumR+=*walker2;
            if((*walker2)%2==0){
                int num = (int)(walker-A);
                ++rowEven[num];
            }
            printf("%d\t", *walker2);
            ++walker2;
        }
        printf("\n");
        if(sumR>sum){
                sum = sumR;
        }
        ++walker;
    }

    walker = A;
    while(walker<stopper){
        int *walker2 = *walker;
        int *stopper2 = *walker+m;
        int sumR = 0;
        while(walker2<stopper2){
            sumR+=*walker2;
            ++walker2;
        }
        printf("\n");
        walker2 = *walker;
        if(sumR==sum){
            printf("\nRow with largest sum: ");
            while(walker2<stopper2){
                printf("%d\t", *walker2);
                ++walker2;
            }
        }

        ++walker;
    }

    walker = A;
    printf("\n");
    printf("\nRows with at least 2 even numbers: ");
    while(walker<stopper){
        int *walker2 = *walker;
        int *stopper2 = *walker+m;

        printf("\n");
        int numR = (int)(walker-A);
        walker2 = *walker;
        if(rowEven[numR]>=2){
            while(walker2<stopper2){
                printf("%d\t", *walker2);
                ++walker2;
            }
        }
        ++walker;
    }


    int col[m];
    for(int i=0; i<m; ++i){
        col[i]=0;
    }

    walker = A;
     //find column with smallest arithmetic mean
    while(walker<stopper){
        int *walker2 = *walker;
        int *stopper2 = *walker+m;
        int counter = 0;
        while(walker2<stopper2){
            col[counter]+=*walker2;
            ++counter;
            ++walker2;
        }

        ++walker;
    }

    int val = col[0];
    int smallC;
    for(int i=0; i<m; ++i){
        if(col[i]<val){
            val = col[i];
            smallC = i;
        }
    }

    walker = A;
    printf("\n");
    printf("\nColumn with lowest arithmetic average: \n");
    while(walker<stopper){
        int *walker2 = *walker;
        int *stopper2 = *walker+m;
        int counter = 0;
        while(walker2<stopper2){
            if(counter==smallC){
                printf("%d\n", *walker2);
            }
            ++counter;
            ++walker2;
        }

        ++walker;
    }



    free(A);
    return 0;
}
