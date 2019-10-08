#include <stdio.h>
#include <stdlib.h>

void format(FILE *, FILE *);
void display(FILE *);

int main(){
    FILE *myfile = fopen("students.txt", "r");
    FILE *destination = fopen("Alisted.txt", "w");
    format(myfile, destination);
    fclose(destination);
    fclose(myfile);

    FILE *listed = fopen("Alisted.txt", "r");
    display(listed);
    fclose(listed);
    return 0;
}

void display(FILE *file){
    char c;
    while((c=getc(file))!=EOF){
        printf("%c", c);
    }
}

void format(FILE *file, FILE *destination){
    rewind(file);
    char surname[50];
    char name[50];
    int born;
    int year;
    int ECTS;
    double avg;

    while(1){
        int r = fscanf(file, "%49[A-Za-z' ]\n%49[A-Za-z' ]\n%d\n%d\n%d\n%lf\n", surname, name, &born, &year, &ECTS, &avg);
        if(r==EOF){
            break;
        }
        fprintf(destination, "%s;%s;%d;%d;%d;%g\n", surname, name, born, year, ECTS, avg);
    }
}
