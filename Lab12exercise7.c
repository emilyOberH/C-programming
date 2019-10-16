#include <stdlib.h>
#include <stdio.h>

void display(FILE *, FILE *);

int main(){
    FILE *file = fopen("abbreviations.txt", "r");
    FILE *file2 = fopen("abbreviations_modified.txt", "w");
    if(file&&file2){
        display(file, file2);
        printf("\nFile has been formatted and stored in file \"abbreviations_modified.txt\".\n");
        fclose(file);
        fclose(file2);
    }else{
        printf("Could not open file.");
        exit(1);
    }
    return 0;
}

void display(FILE *file, FILE *file2){
    char buffer[20];
    char buffer2[80];
    int counter = 0;
    while(1){
        ++counter;
        int r = fscanf(file, "%s %[^\n]\n", buffer, buffer2);
        fprintf(file2, "\n%s", buffer2);
        fprintf(file2, "\n");

        printf("\n%s", buffer2);
        printf("\n");
        if(r==EOF){
            break;
        }
    }
}
