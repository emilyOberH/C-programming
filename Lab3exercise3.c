#include <stdio.h>
#include <stdio.h>

int main(){
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);

    int counter = 1;
    int num = 0;
    while(num<n){
     num = counter * counter;
     if(num%2==0){
        printf("%d ", num);
     }
     ++counter;
    }
    return 0;
}
