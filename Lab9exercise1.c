#include <stdlib.h>
#include <stdio.h>

struct Student{
    char name[50];
    char surname[50];
    int yearOfBirth;
    int yearOfStudy;
    float sumECTS;
    float average;
};

typedef struct Student Student;
void enterData(Student *, int);
void displayData(Student *, int);
void findBest(Student *, int);
void globalAverage(Student *, int);

int main(){
    int n;
    printf("\nHow many students? ");
    scanf("%d", &n);

    Student *A=(Student*)malloc(n*sizeof(Student));
    enterData(A, n);
    displayData(A, n);
    findBest(A, n);
    globalAverage(A, n);

    free(A);
    return 0;
}

void enterData(Student *A, int n){
    Student *walker = A;
    Student *stopper = A+n;
    while(walker<stopper){
        printf("\nName of student? ");
        fflush(stdin);
        scanf("%s", (*walker).name);
        printf("\nSurname of student? ");
        scanf("%s", (*walker).surname);
        printf("\nYear of birth of student? ");
        scanf("%d", &(*walker).yearOfBirth);
        printf("\nYear of study of student? ");
        scanf("%d", &(*walker).yearOfStudy);
        printf("\nSum of ECTS points? ");
        scanf("%f", &(*walker).sumECTS);
        printf("\nAverage of grades? ");
        scanf("%f", &(*walker).average);
        ++walker;
        printf("\n");
    }
    printf("\n");
}

void displayData(Student *A, int n){
    Student *walker = A;
    Student *stopper = A+n;
    while(walker<stopper){
        printf("\nName: %s", (*walker).name);
        printf("\nSurname: %s", (*walker).surname);
        printf("\nYear of birth of student: %d", (*walker).yearOfBirth);
        printf("\nYear of study of student: %d", (*walker).yearOfStudy);
        printf("\nSum of ECTS points: %g", (*walker).sumECTS);
        printf("\nAverage of grades: %g", (*walker).average);
        ++walker;
        printf("\n");
    }
    printf("\n");
}

void findBest(Student *A, int n){
    Student *walker = A;
    Student *stopper = A+n;
    Student *best = A;
    float bestAvg = (*walker).average;

    while(walker<stopper){
        if((*walker).average>bestAvg){
            bestAvg = (*walker).average;
            best = walker;
        }
        ++walker;
    }
    printf("\nBest student is:");
    Student *B=(Student*)malloc(1*sizeof(Student));
    B = best;
    displayData(B, 1);
    free(B);
}

void globalAverage(Student *A, int n){
    Student *walker = A;
    Student *stopper = A+n;
    float avg = 0.0;

    while(walker<stopper){
        avg += (*walker).average;
        ++walker;
    }
    printf("\nGlobal average of all students is: %g", avg);
}
