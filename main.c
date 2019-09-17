#include <stdio.h>
#include <stdlib.h>
#include "point.h"


int main(){
    int n = 2;
    Point *origin = (Point*)malloc(1*sizeof(Point));
    Point *base = (Point*)malloc(1*sizeof(Point));
    base->x=0;
    base->y=0;

    Point *A = (Point*)malloc(n*sizeof(Point));
    printf("\nEnter the first point: ");
    enterData(origin, 1);
    printf("\nDistance to (0,0): ");
    distance(origin, 1, base[0]);

    printf("\nHow many points? ");
    scanf("%d", &n);
    printf("\nNow enter %d more points: ", n);
    enterData(A, n);

    printf("\nPoint closest to the very first point(%d/%d) entered: ", origin->x, origin->y);
    distance(A, n, origin[0]);

    free(A);
    free(origin);
return 0;
}

void enterData(Point *A, int n){
    Point *walker = A;
    Point *stopper = A+n;
    while(walker<stopper){
        printf("\nEnter x coordinate of point %d out of %d: ", (int)(walker-A)+1, n);
        scanf("%d", &(walker->x));
        printf("\nEnter y coordinate of point %d out of %d: ", (int)(walker-A)+1, n);
        scanf("%d", &(walker->y));
        ++walker;
    }
}

void distance(Point *A, int n, Point B){
    Point *walker = A;
    Point *stopper = A+n;
    Point answer = *A;
    double dist = sqrt(pow((B.x)-(walker->x),2) + pow((B.y)-(walker->y),2));
    if(dist<0){
            dist*=(-1);
    }

    do{
        double tmp = sqrt(pow((B.x)-(walker->x),2) + pow((B.y)-(walker->y),2));
        if(tmp<0){
            tmp*=(-1);
        }
        if(tmp<dist){
            dist=tmp;
            answer = *walker;
        }
        ++walker;
    }while(walker<stopper);

    printf("\nDistance is: %g\nAt point(%d/%d)\n", dist, answer.x, answer.y);
}
