#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void hours(int *, double*, double*, int, ...);

int main(){
    int counter = 1;
    double time = 0;
    double total = 0;
    int n=50;
    char given[n];
    char s[2] = " ";
    printf("Enter the hours parked by each customer(separated by space):\n");
    scanf("%[^\n]", given);

    printf("\nCar\tHours\tCharge");

    char *token = strtok(given, s);
    while(token!=NULL){
        hours(&counter, &time, &total, 1, atof(token));
        token = strtok(NULL, s);
    }
    printf("\nTOTAL\t%g\t%g", time, total);
    return 0;
}

void hours(int *a, double *time, double *total, int num, ...){
    va_list list;
    va_start(list, num);

    for(int i=0; i<num; ++i){
        int price = 20;
        float value = va_arg(list, double);
        (*time)+=value;
        for(int j=0; j<=24; ++j){
            if(j>value){
                break;
            }
            if(j>3&&j%1==0){
                price+=5;
            }
        }
        if(price>50){
            price=50;
        }
        (*total)+=price;
        printf("\n%d\t%g\t%d", *a, value, price);
        ++(*a);
    }
    va_end(list);
}
