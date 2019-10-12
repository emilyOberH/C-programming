#include <stdio.h>
#include <stdlib.h>

void display(FILE *);

int main(){
    FILE *myfile = fopen("numbers.bin", "rb");
    if(myfile){
        display(myfile);
    }else{
        printf("\nCould not open file.");
        exit(1);
    }
    fclose(myfile);
    return 0;
}

void display(FILE *file){
    int num;
    int counter;
    rewind(file);
    int sum = 0;
    while(fread(&num, sizeof(int), 1, file)){
        printf("%d ", num);
        sum += num;
        ++counter;
    }
    printf("\n\nSum of all integers in binary file: %d\n", sum);
    printf("\nAverage of all integers in binary file: %g\n", sum/(double)counter);
}
