#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float rectangleArea(float, float, float, float );
float rectangleCircumference(float, float, float, float );
int rectangleSides(float, float, float, float );

int main(){
char ans;
do{
    system("cls");
    float a, b, c, d;
    printf("\nEnter first side length: ");
    scanf("%f", &a);
    printf("\nEnter second side length: ");
    scanf("%f", &b);
    printf("\nEnter third side length: ");
    scanf("%f", &c);
    printf("\nEnter fourth side length: ");
    scanf("%f", &d);

    if(rectangleSides(a,b,c,d)==4){
        printf("\nCircumference of rectangle is: %g", rectangleCircumference(a,b,c,d));
        printf("\nArea of rectangle is: %g", rectangleArea(a,b,c,d));

    }else{
        printf("\nTo form a rectangle we need two pairs of sides of equal length.");
    }

    printf("\nRepeat program? (y/n)");
    scanf(" %c", &ans);
}while(ans=='y'||ans=='Y');
}

float rectangleArea(float a,float b, float c, float d){
    float first = a;
    float second = (a!=b)?b:c;
    return first*second;
}

float rectangleCircumference(float a,float b, float c, float d){
    return a+b+c+d;
}

int rectangleSides(float a,float b, float c, float d){
    int counter = 0;
    if(a==b||a==c||a==d){
        ++counter;
    }
    if(b==a||b==c||b==d){
        ++counter;
    }
    if(c==b||c==a||c==d){
        ++counter;
    }
    if(d==b||d==c||d==a){
        ++counter;
    }
    return counter;
}
