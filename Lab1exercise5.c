#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1;
    printf("\nEnter coordinates of the first point: ");
    printf("\nx: ");
    scanf("%d", &x1);
    printf("\ny: ");
    scanf("%d", &y1);

    int x2, y2;
    printf("\n\nEnter coordinates of the second point: ");
    printf("\nx: ");
    scanf("%d", &x2);
    printf("\ny: ");
    scanf("%d", &y2);


    if ((x1==x2)&&(y1==y2)){
        printf("\nThe line could not be found, as the points are identical");
    }else if ((x1-x2)==0){
        printf("\nThe line is given by the formula: x=%d", x1);
    }else{
        float slope = (double)(y1-y2)/(double)(x1-x2);
        float b = y1-(slope*y2);
        char sym = (b<0)?' ':'+';
        printf("\nThe line is given by the formula: y= %gx%c%g", slope, sym, b);
    }

    return 0;
}
