#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, d, x;
    double answ;
    printf("\nEnter values for the function y=(ax+b)/(cx+d)");
    printf("\na: ");
    scanf("%d", &a);
    printf("\nb: ");
    scanf("%d", &b);
    printf("\nc: ");
    scanf("%d", &c);
    printf("\nd: ");
    scanf("%d", &d);
    printf("\nx: ");
    scanf("%d", &x);
    int denom = c*x+d;

    printf("\nValue of function y=(ax+b)/(cx+d) is: ");
    if(denom==0){
        printf("none (division by zero)");
    }else{
        answ = (a*x+b)/(float)denom;
        printf("%g", answ);
    }

    return 0;
}
