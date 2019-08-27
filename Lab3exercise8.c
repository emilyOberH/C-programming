#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2, m1, m2;
    printf("\nFirst range of multiplication table ");
    printf("\nStart value: ");
    scanf("%d", &n1);
    printf("\nLast value: ");
    scanf("%d", &m1);

    printf("\nSecond range of multiplication table ");
    printf("\nStart value: ");
    scanf("%d", &n2);
    printf("\nLast value: ");
    scanf("%d", &m2);

    for(int k=n1; k<=m1; ++k){
        if(k==n1){
            printf("*\t");
        }
            printf("%d\t", k);
    }
    printf("\n");

    for(int i=n2; i<=m2; ++i){
        printf("%d\t", i);
        for(int j=n1; j<=m1; ++j){
            printf("%d\t", i*j);
        }
        printf("\n");
    }

    return 0;
}
