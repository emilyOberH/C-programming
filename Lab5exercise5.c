#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

void board(int **, int **, int **, int, int*, int*, int*, int*);

int main(){
    srand(time(NULL));
    int counter = 0;
    int n = 10;
    int **A = (int**)malloc(n*sizeof(int*));
    int **walker = A;
    int **stopper = A+n;

    while(walker<stopper){
        *walker = (int*)malloc(n*sizeof(int));
        ++walker;
    }
    walker = A;
    while(walker<stopper){
        int *walkerA = *walker;
        int *stopperA = *walker+n;
        while(walkerA<stopperA){
            *walkerA = (rand()%100)%4;
            ++walkerA;
        }
        ++walker;
    }
    walker = A;

    int x=1, y=1;
    int counterA = -65;
    while(counter<100){
        board( A, walker, stopper, n, &x, &y, &counterA, &counter);
        sleep(1);
        ++counter;
    }


    free(A);
    return 0;
}

void board(int **A, int **walker, int **stopper, int n, int *x, int *y, int *counter, int *loop){
    system("cls");
    A[*x][*y] = *counter;
    while(walker<stopper){
        int *walkerA = *walker;
        int *stopperA = *walker+n;
        while(walkerA<stopperA){
            if(*walkerA<0){
                printf("%c ", (*walkerA)*(-1));
            }else{
                printf("%c ", '.');
            }
            ++walkerA;
        }
        printf("\n");
        ++walker;
    }
    int minX = *x-1;
    int maxX = *x+1;
    int minY = *y-1;
    int maxY = *y+1;
    bool found = false;

    if(found==false){
        for(int i=minX; i<=maxX; ++i){
        if(found){
            break;
        }
        if(i<0||i>99){
            continue;
        }else{
            for(int j=minY; j<=maxY; ++j){
                if(j<0||j>99||(i==minX&&j==minY)||(i==minX&&j==maxY)||(i==maxX&&j==minY)||(i==maxX&&j==maxY)){
                    continue;
                }else{
                    if(A[i][j]==2){
                        A[i][j]=*counter;
                        --(*counter);
                        if(*counter<=-91){
                            *counter = -65;
                        }
                        *x=i;
                        *y=j;
                        found=true;
                        break;
                    }
                }
            }
        }
        }
    }

    if(found==false){
       for(int i=minX; i<=maxX; ++i){
        if(found){
            break;
        }
        if(i<0||i>99){
            continue;
        }else{
            for(int j=minY; j<=maxY; ++j){
                if(j<0||j>99||(i==minX&&j==minY)||(i==minX&&j==maxY)||(i==maxX&&j==minY)||(i==maxX&&j==maxY)){
                    continue;
                }else{
                    if(A[i][j]==3){
                        A[i][j]=*counter;
                        --(*counter);
                        if(*counter<=-91){
                            *counter = -65;
                        }
                        *x=i;
                        *y=j;
                        found=true;
                        break;
                    }
                }
            }
        }
        }
    }

    if(found==false){
     for(int i=minX; i<=maxX; ++i){
        if(found){
            break;
        }
        if(i<0||i>99){
            continue;
        }else{
            for(int j=minY; j<=maxY; ++j){
                if(j<0||j>99||(i==minX&&j==minY)||(i==minX&&j==maxY)||(i==maxX&&j==minY)||(i==maxX&&j==maxY)){
                    continue;
                }else{
                    if(A[i][j]==1){
                        A[i][j]=*counter;
                        --(*counter);
                        if(*counter<=-91){
                            *counter = -65;
                        }
                        *x=i;
                        *y=j;
                        found=true;
                        break;
                    }
                    if(A[i][j]==0){
                        A[i][j]=*counter;
                        --(*counter);
                        if(*counter<=-91){
                            *counter = -65;
                        }
                        *x=i;
                        *y=j;
                        found=true;
                        break;
                    }
                }
            }
        }
    }
    }

    if(found==false){
        printf("Oh, no! Our random walker is stuck.");
        (*loop)=100;
    }

}
