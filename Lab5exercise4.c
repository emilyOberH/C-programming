#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    srand(time(NULL));
    int n, m;
    int a, b;

    printf("\nNumber of rows in first matrix: ");
    scanf("%d", &n);
    printf("\nNumber of columns in first matrix: ");//
    scanf("%d", &m);
    printf("\nNumber of rows in second matrix: ");//
    scanf("%d", &a);
    printf("\nNumber of columns in second matrix: ");
    scanf("%d", &b);

    if(m!=a){
        printf("\nMatrices cannot be multiplied with each other.\nNumber of columns of first matrix has to be equal to the number of rows in second matrix. ");
    }else{
        int **A = (int**)malloc(n*sizeof(int *));
        int **B = (int**)malloc(a*sizeof(int *));
        int **walkerA = A;
        int **stopperA = A+n;
        int **walkerB = B;
        int **stopperB = B+a;

        while(walkerA<stopperA){
            *walkerA = (int *)malloc(m*sizeof(int));
            ++walkerA;
        }
        walkerA = A;
        while(walkerB<stopperB){
            *walkerB = (int *)malloc(b*sizeof(int));
            ++walkerB;
        }
        walkerB = B;

        while(walkerA<stopperA){
            int *walkerAI = *walkerA;
            int *stopperAI = *walkerA+m;
            while(walkerAI<stopperAI){
                *walkerAI = rand()%100;
                ++walkerAI;
            }
            ++walkerA;
        }
        walkerA = A;
        while(walkerB<stopperB){
            int *walkerBI = *walkerB;
            int *stopperBI = *walkerB+b;
            while(walkerBI<stopperBI){
                *walkerBI = rand()%100;
                ++walkerBI;
            }

            ++walkerB;
        }
        walkerB = B;

        printf("First matrix:\n");
        while(walkerA<stopperA){
            int *walkerAI = *walkerA;
            int *stopperAI = *walkerA+m;
            while(walkerAI<stopperAI){
                printf("%d\t", *walkerAI);
                ++walkerAI;
            }
            printf("\n");
            ++walkerA;
        }
        walkerA = A;
        printf("\nSecond matrix:\n");
        while(walkerB<stopperB){
            int *walkerBI = *walkerB;
            int *stopperBI = *walkerB+b;
            while(walkerBI<stopperBI){
                printf("%d\t", *walkerBI);
                ++walkerBI;
            }
            ++walkerB;
            printf("\n");
        }
        walkerB = B;

        printf("\nFirst matrix multiplied by second matrix:\n");
        int **C = (int**)malloc(n*sizeof(int *));
        int **walkerC = C;
        int **stopperC = C+n;
        while(walkerC<stopperC){
            *walkerC = (int *)malloc(b*sizeof(int));
            ++walkerC;
        }
        walkerC = C;

        int counter = 0;
        while(walkerC<stopperC){
            int *walkerCI = *walkerC;
            int *stopperCI = *walkerC+b;
            int innerB = 0;
            while(walkerCI<stopperCI){
                int store = 0;
                int inner = 0;

                for(int i=0; i<a; ++i){
                    store += A[counter+inner][i] * B[i][counter+innerB-counter] ;
                    //printf("\n%d %d",A[counter+inner][i], B[i][counter+innerB-counter]);
                    if(i==(a-1)){
                        inner+=1;
                        innerB+=1;
                        break;
                    }
                }
                *walkerCI = store;
                ++walkerCI;
            }
            ++walkerC;
            ++counter;
        }
        walkerC = C;
        while(walkerC<stopperC){
            int *walkerCI = *walkerC;
            int *stopperCI = *walkerC+b;
            while(walkerCI<stopperCI){
                printf("%d\t", *walkerCI);
                ++walkerCI;
            }
            printf("\n");
            ++walkerC;
        }
        walkerC = C;

        free(A);
        free(B);
        free(C);
    }

    return 0;
}
