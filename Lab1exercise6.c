#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)

int main(){
    int r=-1, h=-1;
    double volume, area;
    while(r<0||h<0){
        printf("\nEnter value of radius: ");
        scanf("%d", &r);
        printf("\nEnter value of height: ");
        scanf("%d", &h);
    }
    volume = (1.0/3.0)*PI*pow(r,2)*h;
    area = PI*r*(r+sqrt(pow(r,2)+pow(h,2)));
    printf("\nVolume of cone is: %g", volume);
    printf("\nArea of cone is: %g", area);

    return 0;
}
