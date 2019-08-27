#include <stdio.h>
#include <stdlib.h>

int main(){
    int nom, denom, a, b, gcd;
    printf("\nEnter a fraction: ");
    scanf("%d/%d", &nom, &denom);
    if(nom>denom){
        a=nom;
        b=denom;
    }else{
        a=denom;
        b=nom;
    }
    if(a<0){
        a=a*(-1);
    }
    if(b<0){
        b=b*(-1);
    }

    int rest=1;
    while(rest!=0){
        gcd=b;
        rest=a%b;
        a=b;
        b=rest;
    }

    printf("\n%d/%d = %d/%d", nom, denom, nom/gcd, denom/gcd);
    return 0;
}
