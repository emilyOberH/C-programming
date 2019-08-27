#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int sum = 0;
    printf("\nHow many integers? ");
    scanf("%d", &n);
    int *A=(int*)malloc(n*sizeof(int));

    printf("\nEnter %d integers: ", n);
    int *walker = A;
    int *stopper = A+n;
    while(walker<stopper){
        printf("\n#%d: ", (int)(walker-A)+1);
        scanf("%d", &(*walker));
        ++walker;
    }
    walker = A;
    while(walker<stopper){
        sum += *walker;
        ++walker;
    }
    printf("\nSum is: %d", sum);
    printf("\nAverage is: %g", (double)sum/n);

    free(A);
    return 0;
}
