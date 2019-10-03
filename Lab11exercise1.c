#include <stdio.h>
#include <stdlib.h>

void displayStudents(FILE *);
void betterStudents(FILE *, FILE *, double);

int main(){
    double grade = 0.0;
    while(grade<1.0||grade>4.99){
        printf("\nEnter a grade average between 1.0 and 4.99: ");
        scanf("%lf", &grade);
    }

    FILE *myfile = fopen("listOfStudents.txt", "r");
    printf("List of all students:\n");
    displayStudents(myfile);
    fclose(myfile);

    FILE *fileNEW = fopen("someStudents.txt", "w");
    FILE *fileOLD = fopen("listOfStudents.txt", "r");
    printf("\nA file named \"someStudents.txt\" has been created in the current directory.\nIt contains all students with a grade average higher than the one you entered (%g).\n", grade);
    betterStudents(fileOLD, fileNEW, grade);
    fclose(fileNEW);
    fclose(fileOLD);

    FILE *display = fopen("someStudents.txt", "r");
    printf("\nStudents with a grade average higher than the one you entered (%g):\n", grade);
    displayStudents(display);
    fclose(display);
    return 0;
}

void displayStudents(FILE *file){
    rewind(file);
    char surname[50];
    char name[50];
    int year;
    int studyYear;
    int ECTS;
    double average;

    while(1){
        int r = fscanf(file, "%49[A-Za-z' ];%49[A-Za-z' ];%d;%d;%d;%lf\n", surname, name, &year, &studyYear, &ECTS, &average);
        if(r==EOF){
            break;
        }
        printf("\nSurname:\t%s", surname);
        printf("\nName:\t\t%s", name);
        printf("\nBorn:\t\t%d", year);
        printf("\nStudy year:\t%d", studyYear);
        printf("\nECTS:\t\t%d", ECTS);
        printf("\nGrade average:\t%g\n", average);


    }

}

void betterStudents(FILE *old, FILE *best, double grade){
    rewind(old);
    char surname[50];
    char name[50];
    int year;
    int studyYear;
    int ECTS;
    double average;

    while(1){
        int r = fscanf(old, "%49[A-Za-z' ];%49[A-Za-z' ];%d;%d;%d;%lf\n", surname, name, &year, &studyYear, &ECTS, &average);
        if(r==EOF){
            break;
        }
        if(average>grade){
            fprintf(best, "%s;", surname);
            fprintf(best, "%s;", name);
            fprintf(best, "%d;", year);
            fprintf(best, "%d;", studyYear);
            fprintf(best, "%d;", ECTS);
            fprintf(best, "%g\n", average);
        }

    }

}
