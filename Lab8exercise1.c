#include <stdlib.h>
#include <stdio.h>

struct Fraction {
    int nom;
    int denom;
};

typedef struct Fraction Fraction; // "struct Fraction one" can becomes "Fraction one"

int lcd(int, int);
void sum(Fraction *,Fraction *);
void difference(Fraction *,Fraction *);
void product(Fraction *,Fraction *);
void quotient(Fraction *,Fraction *);

int main(){
    Fraction one;
    Fraction two;

    printf("Enter the nominator of the first fraction: ");
    scanf("%d", &one.nom);
    printf("\nEnter the denominator of the first fraction: ");
    scanf("%d", &one.denom);
    printf("\nEnter the nominator of the second fraction: ");
    scanf("%d", &two.nom);
    printf("\nEnter the denominator of the second fraction: ");
    scanf("%d", &two.denom);

    sum(&one, &two);
    difference(&one, &two);
    product(&one, &two);
    quotient(&one, &two);
    printf("\n");

    return 0;
}
void sum(Fraction *A,Fraction *B){
    int denominator = lcd(A->denom, B->denom);
    int nominator = ((A->nom)*(denominator/A->denom))+((B->nom)*(denominator/B->denom));
    printf("\nSum of %d/%d and %d/%d is: %d/%d", A->nom, A->denom, B->nom, B->denom, nominator, denominator);
}

void difference(Fraction *A,Fraction *B){
    int denominator = lcd(A->denom, B->denom);
    int nominator = ((A->nom)*(denominator/A->denom))-((B->nom)*(denominator/B->denom));
    printf("\nDifference of %d/%d and %d/%d is: %d/%d", A->nom, A->denom, B->nom, B->denom, nominator, denominator);
}

void product(Fraction *A,Fraction *B){
    int denominator = (A->denom)*(B->denom);
    int nominator =  (A->nom)*(B->nom);
    printf("\nProduct of %d/%d and %d/%d is: %d/%d", A->nom, A->denom, B->nom, B->denom, nominator, denominator);
}

void quotient(Fraction *A,Fraction *B){
    int nominator = (A->nom)*(B->denom);
    int denominator =  (A->denom)*(B->nom);
    printf("\nQuotient of %d/%d and %d/%d is: %d/%d", A->nom, A->denom, B->nom, B->denom, nominator, denominator);
}

int lcd(int n, int m){
    int tmp = 0;
    if(m<n){
        n = tmp;
        n = m;
        m = tmp;
    }
    int lcd = n*m;
    for(int i=1; i<n; ++i){
        if((i*n)%m==0){
            lcd = i*n;
        }
    }

    return lcd;
}
