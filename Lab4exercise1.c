#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("\nHow many? ");
    scanf("%d", &n);

    int *A = (int*)malloc(n*sizeof(int));
    int *walker = A;
    int *stopper = A+n;
    while(walker<stopper){
        printf("\n#%d: ", (int)(stopper-walker));
        scanf("%d", &(*walker));
        ++walker;
    }
    walker = A;
    int max = *walker;
    while(walker<stopper){
        if(*walker>max){
           max = *walker;
        }
        ++walker;
    }
    printf("\nGreatest number: %d",  max);

    walker = A;
    int counter = 0;
    while(walker<stopper){
        if(*walker!=max){
           ++counter;
        }
        ++walker;
    }
    printf("\nNumber of integers different than %d: %d",  max, counter);

    walker = A;
    int sum = 0;
    while(walker<stopper){
        if(*walker!=max){
           sum+=*walker;
        }
        ++walker;
    }
    printf("\nSum of integers different than %d: %d",  max, sum);
    printf("\nAverage of integers different than %d: %g",  max, (double)sum/(double)counter);

    free(A);
    return 0;
}
