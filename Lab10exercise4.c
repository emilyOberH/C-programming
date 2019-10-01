#include <stdio.h>
#include <stdlib.h>

void mergeFiles(FILE *, FILE *, FILE *);
void display(FILE *);

int main(){
    FILE *myfile = fopen("file1.c", "r");
    FILE *myfileB = fopen("file2.c", "r");
    FILE *myfileM = fopen("merge.txt", "w");
    mergeFiles(myfile, myfileB, myfileM);
    fclose(myfile);
    fclose(myfileB);
    fclose(myfileM);

    FILE *myfileM2 = fopen("merge.txt", "r");
    display(myfileM2);
    fclose(myfileM2);
    return 0;
}

void mergeFiles(FILE *A, FILE *B, FILE *M){
    char c;
    while((c=getc(A))!=EOF){
        fprintf(M, "%c", c);
    }
    while((c=getc(B))!=EOF){
        fprintf(M, "%c", c);
    }
}

void display(FILE *A){
    char c;
    printf("\nContent of merged file:\n\n");
    while((c=getc(A))!=EOF){
        printf("%c", c);
    }
    printf("\n");
}
