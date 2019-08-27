#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=-1, m=-1;
    while(n<0&&m<0){
        printf("\nEnter two positive integers: ");
        scanf("%d %d", &n, &m);
    }

    printf("\nMultiples of %d smaller than %d: ", n, m);

    int counter = 0;
    for(int i=1; i<=m; ++i){
        counter=n*i;
        if(counter>=m){
            break;
        }
        printf("%d ", n*i);
    }
    return 0;
}
