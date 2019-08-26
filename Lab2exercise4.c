#include <stdio.h>

int main(){
    int d, m, y;
    printf("\nEnter date (dd/mm/yy): ");
    scanf("%d/%d/%d", &d, &m, &y);

    int d2, m2, y2;
    printf("\nEnter second date (dd/mm/yy): ");
    scanf("%d/%d/%d", &d2, &m2, &y2);

    printf("\n%d/%d/%d is ", d, m, y);
    if(y<y2){
        printf("earlier than");
    }else if(y>y2){
        printf("later");
    }else{
        if(m<m2){
            printf("earlier than");
        }else if(m>m2){
            printf("later");
        }else{
            if(m<m2){
                printf("earlier");
            }else if(m>m2){
                printf("later");
            }else{
                printf("the same as");
            }
        }
    }
    printf(" %d/%d/%d.", d2, m2, y2);
    return 0;
}
