#include <stdio.h>
#include <stdlib.h>

void best(FILE *, int year);

int main(){

    FILE *findBest = fopen("students.txt", "r");
    printf("\nBest first year student(s):\n");
    best(findBest, 1);
    printf("\n");
    printf("\nBest second year student(s):\n");
    best(findBest, 2);
    printf("\n");
    printf("\nBest third year student(s):\n");
    best(findBest, 3);
    printf("\n");
    printf("\nBest student(s) overall:\n");
    best(findBest, 4);
    fclose(findBest);
    return 0;
}


void best(FILE *file, int grade){
    rewind(file);
    char surname[50];
    char name[50];
    int born;
    int year;
    int ECTS;
    double avg;

    double bestAvg;
    fscanf(file, "%49[A-Za-z' ]\n%49[A-Za-z' ]\n%d\n%d\n%d\n%lf\n", surname, name, &born, &year, &ECTS, &bestAvg);;

    while(1){
        int r = fscanf(file, "%49[A-Za-z' ]\n%49[A-Za-z' ]\n%d\n%d\n%d\n%lf\n", surname, name, &born, &year, &ECTS, &avg);
        if(r==EOF){
            break;
        }
        if(year==grade||grade==4){
            if(avg>bestAvg){
                bestAvg = avg;
            }
        }
    }
    rewind(file);
        while(1){
        int r = fscanf(file, "%49[A-Za-z' ]\n%49[A-Za-z' ]\n%d\n%d\n%d\n%lf\n", surname, name, &born, &year, &ECTS, &avg);
        if(r==EOF){
            break;
        }
        if(avg==bestAvg){
            printf("\nSurname: %s", surname);
            printf("\nName: %s", name);
            printf("\nBorn: %d", born);
            printf("\nStudy year: %d", year);
            printf("\nECTS: %d", ECTS);
            printf("\nAverage: %g", avg);
            printf("\n");
        }
    }
}

