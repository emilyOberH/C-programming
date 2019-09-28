#include <stdlib.h>
#include <stdio.h>

void appendLines(FILE *, int);
void displayLines(FILE *, int);
void copyFile(FILE *, FILE*);

int main(){
    int n;
    printf("\nAppend how many lines of text? ");
    scanf("%d", &n);
    FILE *myfile = fopen("story.txt", "a");
    appendLines(myfile, n);
    fclose(myfile);


    FILE *myfileB = fopen("story.txt", "r");
    displayLines(myfileB, n);
    fclose(myfileB);

    FILE *myfileC = fopen("story.txt", "r");
    FILE *copy = fopen("story_copy.txt", "w");
    copyFile(myfileC, copy);
    fclose(copy);
    fclose(myfileC);
    return 0;
}

void appendLines(FILE *myfile, int n){
    for(int i=0; i<n; ++i){
        fprintf(myfile, "\nLine %d out of %d", i+1, n);
    }
}

void displayLines(FILE *myfile, int n){
    char i;
    int counter = 0;
    if(myfile){
        while((i=fgetc(myfile))!=EOF){
            printf("%c", i);
            if(i=='\n'){
                ++counter;
            }
        }
    }
    printf("\n\nNumber of total lines in file: %d", counter);
}

void copyFile(FILE *myfile, FILE *copy){
    char i;
    while((i=fgetc(myfile))!=EOF){
        fputc(i, copy);
    }
    printf("\nContent of file (story.txt) has been copied to file story_copy.txt");
}
