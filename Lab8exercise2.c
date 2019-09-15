#include <stdlib.h>
#include <stdio.h>

struct Fraction {
    int nom;
    int denom;
};

typedef struct Fraction Fraction;

int lcd(int, int);
void sum(Fraction *,Fraction *);
void difference(Fraction *,Fraction *);
void product(Fraction *,Fraction *);
void quotient(Fraction *,Fraction *);
void askUser(Fraction *, int);
void printFrac(Fraction *, int);
void largestFrac(Fraction *, int);

int main(){
    int n = 2;
    Fraction *A = (Fraction*)malloc(n*sizeof(Fraction));

    askUser(A, n);
    printFrac(A, n);
    largestFrac(A, n);
    printf("\n");

    return 0;
}

void askUser(Fraction *A, int n){
    Fraction *walker = A;
    Fraction *stopper = A+n;

    while(walker<stopper){
        printf("\nEnter the nominator of fraction #%d: ", (int)(walker-A)+1);
        scanf("%d", &(*walker).nom);
        printf("\nEnter the denominator of fraction #%d: ", (int)(walker-A)+1);
        scanf("%d", &(*walker).denom);
        ++walker;
    }
}

void printFrac(Fraction *A, int n){
    Fraction *walker = A;
    Fraction *stopper = A+n;

    printf("\n");
    while(walker<stopper){
        printf("%d/%d\t", (*walker).nom, (*walker).denom);
        ++walker;
    }
}

void largestFrac(Fraction *A, int n){
    Fraction *walker = A;
    Fraction *stopper = A+n;
    double store = ((double)((*walker).nom)) / ((double)((*walker).denom));
    int nomi = ((*walker).nom);
    int denomi = ((*walker).denom);

    while(walker<stopper){
        double next = ((double)((*walker).nom)) / ((double)((*walker).denom));
        if(next>store){
            store = next;
            nomi = ((*walker).nom);
            denomi = ((*walker).denom);
        }
        ++walker;
    }
    printf("\nLargest fraction: %d/%d\t", nomi, denomi);
}
