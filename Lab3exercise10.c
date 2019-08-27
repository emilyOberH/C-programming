#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

int main(){
    int num=-1;
    while(num<1){
        printf("\nEnter a positive number: ");
        scanf("%d", &num);
    }

    printf("\nAll positive number smaller than %d, which are relative prime to %d.\n", num, num);
    for(int i=1; i<num; ++i){
        int divisor = gcd(i,num);
        if(divisor==1){
            printf("%d\t", i);
        }
    }

    return 0;
}

int gcd(int a, int b){
    int gcd=1;
    int rest=1;
    while(rest!=0){
        gcd=b;
        rest=a%b;
        a=b;
        b=rest;
    }
    return gcd;
}
