#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

int main(){
    int a, b, c;
    printf("\nEnter 3 positive integers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("\nGCD of %d, %d and %d is %d", a, b, c, gcd(gcd(a,b),c));
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
