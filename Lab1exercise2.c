#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, arg, ans1;
    printf("Program outputs the value of a square function.\nEnter the coefficients: ");
    printf("\na: ");
    scanf("%f", &a);
    printf("\nb: ");
    scanf("%f", &b);
    printf("\nc: ");
    scanf("%f", &c);
    printf("\nEnter value of argument: ");
    scanf("%f", &arg);

    printf("\nValue of square function with coefficients %g, %g and %g at %g ", a, b, c, arg);

    ans1 = a*pow(arg,2)+b*arg+c;
    printf("is %g", ans1);

    return 0;
}
