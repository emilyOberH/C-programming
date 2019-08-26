#include <stdio.h>

int main(){
    int d, m, y;
    printf("\nEnter date (dd/mm/yy): ");
    scanf("%d/%d/%d", &d, &m, &y);
    int D = d%10;

    printf("\nDated this %d", d);
    switch(D){
    case 1:
        printf("st");
        break;
    case 2:
        printf("nd");
        break;
    case 3:
        printf("rd");
        break;
    default:
        printf("th");
        break;
    }

    printf(" day of ");
    switch(m){
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    }

    printf(", 20%d", y);
    return 0;
}
