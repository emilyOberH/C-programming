#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

float circleArea(float);
float circleCircumference(float);

int main(){
    int r;
    printf("\nEnter radius value of circle: ");
    scanf("%d", &r);

    printf("\nThe area of the circle is: %g",circleArea(r));
    printf("\nThe circumference of the circle is: %g\n",circleCircumference(r));

    return 0;
}

float circleArea(float r){
    return M_PI*pow(r,2);
}

float circleCircumference(float r){
    return 2*M_PI*r;
}
