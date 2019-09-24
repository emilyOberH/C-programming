#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point Point;
typedef struct Circle Circle;
void enterData(Point *, int);
double distance(Point , Point);

struct Point{
    float x;
    float y;
};
struct Circle{
    float radius;
    Point center;
};


int main(){
    Circle origin ;

    printf("\nEnter the radius of the circle: ");
    scanf("%f", &(origin.radius));
    printf("\nEnter x coordinate of the circle: ");
    scanf("%f", &(origin.center.x));
    printf("\nEnter y coordinate of the circle: ");
    scanf("%f", &(origin.center.y));

    int n;
    printf("\nCheck how many points? ");
    scanf("%d", &n);
    Point *A = (Point*)malloc(n*sizeof(Point));
    printf("\nNow enter %d more points: ", n);
    enterData(A, n);

    Point *walker = A;
    Point *stopper = A+n;
    while(walker<stopper){
        printf("\nPoint (%g,%g) is", (*walker).x, (*walker).y );
        if(distance(*walker, origin.center)>origin.radius){
            printf(" NOT");
        }
        printf(" in or on he circle.");
        ++walker;
    }

    free(A);
    return 0;
}

void enterData(Point *A, int n){
    Point *walker = A;
    Point *stopper = A+n;
    while(walker<stopper){
        printf("\nEnter x coordinate of point %d out of %d: ", (int)(walker-A)+1, n);
        scanf("%f", &(walker->x));
        printf("\nEnter y coordinate of point %d out of %d: ", (int)(walker-A)+1, n);
        scanf("%f", &(walker->y));
        ++walker;
    }
}

double distance(Point A, Point B){
    double dist = sqrt(pow((B.x)-(A.x),2) + pow((B.y)-(A.y),2));
    return dist;
}

