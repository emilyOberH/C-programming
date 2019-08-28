#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    char ans = 'y';
    do{
        srand(time(NULL));
        int a, b, n;
        printf("\nHow many integers? ");
        scanf("%d", &n);
        printf("\nEnter range: ");
        scanf("%d %d", &a, &b);

        int M = a;
        while(M<2*a||M>2*b){
            printf("\nEnter a M value belonging to the range %d to %d: ", 2*a, 2*b);
            scanf("%d", &M);
        }

        int temp;
        if(b<a){
            temp = a;
            a = b;
            b = temp;
        }

        int *A = (int*)malloc(n*sizeof(int));
        int *walker = A;
        int *stopper = A+n;
        while(walker<stopper){
            *walker = rand()%(b-a+1)+a;
            ++walker;
        }

        walker = A;
        printf("\nArray: ");
        while(walker<stopper){
            printf("%d ", *walker);
            ++walker;
        }

        walker = A;
        while(walker<stopper){
            int *innerWalker = A;
            while(innerWalker<stopper){
                int sum = *walker + *innerWalker;
                if(sum==M&&walker!=innerWalker&&!(innerWalker<walker)){
                    printf("\n{%d,%d}\tIndex in array: %d, %d", *walker, *innerWalker, -1*(int)(A-walker), -1*(int)(A-innerWalker));
                }
                ++innerWalker;
            }

            ++walker;
        }


        free(A);

        fflush(stdin);
        printf("\nRepeat program?(y/n) ");
        scanf("%c", &ans);
    }while(ans=='y'||ans=='Y');
    return 0;
}
