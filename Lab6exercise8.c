#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printDiamond(int);

int main(){
    int r=-1;
    while(r<1||r>30){
        printf("\nEnter height of diamond (between 1 and 30): ");
        scanf("%d", &r);
    }

    printDiamond(r);
    return 0;
}

void printDiamond(int r){
    int neg = 0;
    int g = 1;
    int buffer;
    if(r%2==0){
        g = 2;
    }
    for(int i=0; i<=r; ++i){
        buffer = (r-g)/2;
        /*if(r%(i+1)==2){
            for(int j=0; j<i; ++j){
                printf("%c", '*');
            }
            printf("\n");
        }*/
        for(int j=0; j<buffer; ++j){
            printf(" ");
        }
        for(int j=1; j<=g; ++j){
            printf("%c", '*');
        }
        if(g>=r||neg==1){
            neg = 1;
            g-=2;
        }else{
            g+=2;
        }
        printf("\n");
    }
}

