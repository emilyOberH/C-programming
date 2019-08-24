#include <stdio.h>

int main(){
    int a;
    printf("\nEnter integer: ");
    scanf("%d", &a);
    printf("\nInteger entered: %d", a);

    float b;
    printf("\nEnter real number: ");
    scanf("%f", &b);
    printf("\nReal number entered: %g", b);

    char c;
    printf("\nEnter character: ");
    scanf(" %c", &c);
    printf("\nCharacter entered: %c", c);

    char d[50];
    printf("\nEnter string: ");
    scanf(" %[^\n]s", d);
    printf("\nString entered: %s", d);
}
