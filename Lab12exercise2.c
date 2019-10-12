#include <stdio.h>
#include <stdlib.h>

void display(FILE *);
void write(FILE *, int);

int main(){
    int n;
    printf("\nAppend how many integers? ");
    scanf("%d", &n);
    FILE *mynumbers = fopen("mynumbers.bin", "wb");
    if(mynumbers){
        //int num = 8;
        //fwrite(&num, sizeof(int), 1, mynumbers);
        write(mynumbers, n);
    }else{
        printf("\nCould not open file.");
        exit(1);
    }
    fclose(mynumbers);

    FILE *myfile = fopen("mynumbers.bin", "rb");
    if(myfile){
        printf("\nContents of binary file: ");
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
}

void write(FILE *file, int n){
    rewind(file);
    int num;
    for(int i=0; i<n; ++i){
        int num;
        printf("\nEnter integer %d out of %d: ", i+1, n);
        scanf("%d", &num);
        fwrite(&num, sizeof(num), 1, file);
    }
}

