#include <stdio.h>

int main(){
    int a, b, c, biggest;
    float av;
    printf("\nEnter 3 integers: ");
    scanf("%d %d %d", &a, &b, &c);
    av = (a+b+c)/3.0;

    biggest = ((a>b&&a>c)?a:((b>c)?b:c));
    printf("\nGreatest number: %d", biggest);
    printf("\nAverage of %d, %d and %d: %g", a, b, c, av);
    return 0;
}
