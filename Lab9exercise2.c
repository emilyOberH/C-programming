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
void appendData(Student *, int, FILE *);

int main(){
    int n;
    printf("\nHow many students? ");
    scanf("%d", &n);

    Student *A=(Student*)malloc(n*sizeof(Student));
    enterData(A, n);
    displayData(A, n);
    printf("\nData about students was appended to a file located in the same folder as this program.\n");
    //appendData(A, n);
    FILE *myfile = fopen("allStudents.txt", "w+");
    appendData(A, n, myfile);
    //fprintf(myfile, "%d", 333);
    fclose(myfile);

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

void appendData(Student *A, int n, FILE *myfile){
    Student *walker = A;
    Student *stopper = A+n;
    while(walker<stopper){
        fprintf(myfile, "\nName: %s ", (*walker).name);
        fprintf(myfile, "\nSurname: %s ", (*walker).surname);
        fprintf(myfile, "\nYear of birth of student: %d", (*walker).yearOfBirth);
        fprintf(myfile, "\nYear of study of student: %d", (*walker).yearOfStudy);
        fprintf(myfile, "\nSum of ECTS points: %g", (*walker).sumECTS);
        fprintf(myfile, "\nAverage of grades: %g", (*walker).average);
        ++walker;
        fprintf(myfile, "\n");
    }
}
