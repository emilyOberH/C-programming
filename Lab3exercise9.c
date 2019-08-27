#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    printf("\nEnter number of days in month: ");
    scanf("%d", &num);

    int day;
    printf("\nEnter day of week in which month begins(1-Mon 7-Sun): ");
    scanf("%d", &day);

    for(int i=1; i<=num; ++i){
        if(i==1){
            for(int j=1; j<day; ++j){
                printf("\t");
            }
        }
        printf("%d\t", i);
        int k = i+day-1;
        if(k%7==0){
            printf("\n");
        }
    }

    return 0;
}
