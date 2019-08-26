#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    printf("\nEnter side length #1 of the triangle: ");
    scanf("%d", &a);
    printf("\nEnter side length #2 of the triangle: ");
    scanf("%d", &b);
    printf("\nEnter side length #3 of the triangle: ");
    scanf("%d", &c);

    int max = (a>b&&a>c)?a:((b>c)?b:c);
    int rest = (a+b+c)-max;
    if(rest>=max){
        float s = (a+b+c)/2.0;
        float ar = sqrt(s*(s-a)*(s-b)*(s-c));
        float peri = a+b+c;
        printf("\nThe area is equal to %g and the perimeter is equal to %g", ar, peri);
    }else{
        printf("\nThe area and the perimeter can not be calculated.");
    }

    return 0;
}
