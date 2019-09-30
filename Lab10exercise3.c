#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *myfile = fopen("file1.c", "r");
    char c;
    while((c=getc(myfile))!=EOF){
        printf("%c", c);
    }
    fclose(myfile);

    FILE *myfileB = fopen("file1.c", "r");
    FILE *myfileC = fopen("file1_copy.txt", "w");
    char ch;
    int counter = 1;
    fprintf(myfileC, "%d ", counter);
    while((ch=getc(myfileB))!=EOF){
        fprintf(myfileC, "%c", ch);
        if(ch=='\n'){
            fprintf(myfileC, "%d ", counter);
            ++counter;
        }
    }
    fclose(myfileC);
    fclose(myfileB);
    return 0;
}

