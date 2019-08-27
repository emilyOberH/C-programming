#include <stdio.h>
#include <stdlib.h>

int main(){
    int sum = 0;
    printf("\nEnter 10 digits:");

    int arr[10];
    for(int i=1; i<=10; ++i){
        int num;
        printf("\n#%d: ", i);
        scanf("%d", &num);
        arr[i]=num;
    }
    for(int i=1; i<=10; ++i){
        sum += arr[i];
    }
    printf("\nSum equals: %d", sum);
    printf("\nAverage equals: %g", sum/10.0);

    return 0;
}
