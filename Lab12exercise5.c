#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students{
        char surname[50];
        char name[50];
        int year;
        int studyYear;
        int ECTS;
        double average;
};

void copyTo(FILE *, FILE *);

int main(){
    FILE *myfile = fopen("listOfStudents.txt", "r");
    FILE *binfile = fopen("students.bin", "wb");
    if(myfile&&binfile){
        copyTo(myfile, binfile);

    }else{
        printf("\nFile could not be opened.");
        exit(1);
    }

    return 0;
}

void copyTo(FILE *file, FILE *destination){
    rewind(file);
    char surname[50];
    char name[50];
    int year;
    int studyYear;
    int ECTS;
    double average;
    char col = ';';
    char newL = '\n';
    struct Students tmp;

    while(1){
        int r = fscanf(file, "%49[A-Za-z' ];%49[A-Za-z' ];%d;%d;%d;%lf\n", surname, name, &year, &studyYear, &ECTS, &average);
        if(r==EOF){
            break;
        }

        strcpy(tmp.surname, surname);
        strcpy(tmp.name, name);
        tmp.year = year;
        tmp.studyYear = studyYear;
        tmp.ECTS = ECTS;
        tmp.average = average;


        fwrite(&tmp, sizeof(struct Students), 1, destination);
        /*fwrite(surname, sizeof(surname), 1, destination);
        fwrite(&col, sizeof(col), 1, destination);
        fwrite(name, sizeof(name), 1, destination);
        fwrite(&col, sizeof(col), 1, destination);
        fwrite(&year, sizeof(year), 1, destination);
        fwrite(&col, sizeof(col), 1, destination);
        fwrite(&studyYear, sizeof(studyYear), 1, destination);
        fwrite(&col, sizeof(col), 1, destination);
        fwrite(&ECTS, sizeof(ECTS), 1, destination);
        fwrite(&col, sizeof(col), 1, destination);
        fwrite(&average, sizeof(average), 1, destination);
        fwrite(&newL, sizeof(newL), 1, destination);*/


    }
}
