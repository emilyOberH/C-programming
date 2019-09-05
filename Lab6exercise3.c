#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int);
void factorsOf(int);

int main(){
    int n=-1;
    while(n<1){
        printf("\nEnter a positive integer: ");
        scanf("%d", &n);
    }

    if(isPrime(n)){
        printf("\n%d is a prime number.", n);
    }else{
        printf("\n%d is a not prime number.", n);
    }
    factorsOf(n);

    return 0;
}

bool isPrime(int n){
    int counter = 0;
    for(int i=1; i<=n; ++i){
        if(n%i==0){
            ++counter;
        }
    }
    if(counter==2){
        return true;
    }else{
        return false;
    }
}

void factorsOf(int n){
    printf("\nAll positive factors of %d: ", n);
   for(int i=1; i<=n; ++i){
        if(n%i==0){
            printf("%d ", i);
        }
    }
    printf("\n");
}
