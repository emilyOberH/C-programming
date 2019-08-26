#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool grade (float g);

int main(){
    float g1=0, g2=0, g3=0;
    int w1=-1, w2=-1, w3=-1;

    while(!grade(g1)){
        printf("\nEnter grade #1:");
        scanf("%f",&g1);
    }
    while(!grade(g2)){
        printf("\nEnter grade #2:");
        scanf("%f",&g2);
    }
    while(!grade(g3)){
        printf("\nEnter grade #3:");
        scanf("%f",&g3);
    }

    while(w1<0||w2<0||w3<0){
      if(w1<0){
        printf("\nEnter weight of grade #1:");
        scanf("%d",&w1);
      }
      if(w2<0){
        printf("\nEnter weight of grade #2:");
        scanf("%d",&w2);
      }
      if(w3<0){
        printf("\nEnter weight of grade #3:");
        scanf("%d",&w3);
      }
    }

    double av = (g1*w1+g2*w2+g3*w3)/(w1+w2+w3);
    printf("\nAverage of all weighted grades is: %g", av);
    return 0;
}

bool grade (float g){
    return (g==2||g==3||g==3.5||g==4||g==4.5||g==5)?true:false;
}
