#include <stdio.h>
#include <stdlib.h>

float sumOf3(float, float, float);
float averageOf3(float, float, float);
float largestOf3(float, float, float);

int main(){
    float a, b, c;
    printf("\nEnter first number: ");
    scanf("%f", &a);
    printf("\nEnter second number: ");
    scanf("%f", &b);
    printf("\nEnter third number: ");
    scanf("%f", &c);

    printf("\nSum of %g, %g and %g: %g", a, b, c, sumOf3(a,b,c));
    printf("\nAverage of %g, %g and %g: %g", a, b, c, averageOf3(a,b,c));
    printf("\nLargest value of %g, %g and %g: %g", a, b, c, largestOf3(a,b,c));
    printf("\n");
    return 0;
}


float sumOf3(float a, float b, float c){
    return a+b+c;
}

float averageOf3(float a, float b, float c){
    return (a+b+c)/3;
}

float largestOf3(float a, float b, float c){
    if(a>b&&a>c){
        return a;
    }else if(b>a&&b>c){
        return b;
    }else{
        return c;
    }
}
