#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=-1, m=-1;
    while(n<0&&m<0){
        printf("\nEnter two positive integers: ");
        scanf("%d %d", &n, &m);
    }

    printf("\n%d multiples of %d: ", m, n);

    for(int i=1; i<=m; ++i){
        printf("%d ", n*i);
    }

    return 0;
}
