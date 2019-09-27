#include <stdlib.h>
#include <stdio.h>

struct Participant{
    char name[50];
    float task1;
    float task2;
    float task3;
    float sumOfPoints;
};

typedef struct Participant Participant;
void enterData(Participant *, int);
void displayData(Participant *, int);
float averagePoints(Participant *, int);
void aboveAverage(Participant *, int, float, FILE *);

int main(){
    int n;
    printf("\nHow many participants? ");
    scanf("%d", &n);

    Participant *A = (Participant*)malloc(n*sizeof(Participant));
    enterData(A, n);
    displayData(A, n);
    float avg = averagePoints(A, n);
    FILE *myfile = fopen("aboveAverage.txt", "w+");
    aboveAverage(A, n, avg, myfile);

    fclose(myfile);
    free(A);
    return 0;
}

void enterData(Participant *A, int n){
    Participant *walker = A;
    Participant *stopper = A+n;
    while(walker<stopper){
        printf("\nEnter the name of the participant: ");
        scanf("%s", (*walker).name);
        printf("\nEnter grade for task 1: ");
        scanf("%f", &(*walker).task1);
        printf("\nEnter grade for task 2: ");
        scanf("%f", &(*walker).task2);
        printf("\nEnter grade for task 3: ");
        scanf("%f", &(*walker).task3);
        (*walker).sumOfPoints = (*walker).task1+(*walker).task2+(*walker).task3;
        ++walker;
        printf("\n");
    }
}

void displayData(Participant *A, int n){
    Participant *walker = A;
    Participant *stopper = A+n;
    while(walker<stopper){
        printf("\nName of the participant: %s", (*walker).name);
        printf("\nGrade for task 1: %g", (*walker).task1);
        printf("\nGrade for task 2: %g", (*walker).task2);
        printf("\nGrade for task 3: %g", (*walker).task3);
        printf("\nSum of all  grades: %g", (*walker).sumOfPoints);
        ++walker;
        printf("\n");
    }
}

float averagePoints(Participant *A, int n){
    Participant *walker = A;
    Participant *stopper = A+n;
    float sum = 0.0;
    while(walker<stopper){
        sum+=(*walker).sumOfPoints;
        ++walker;
    }
    return sum/n;
}

void aboveAverage(Participant *A, int n, float avg, FILE *myfile){
    Participant *walker = A;
    Participant *stopper = A+n;
    while(walker<stopper){
        if((*walker).sumOfPoints>=avg){
            fprintf(myfile, "\nName of the participant: %s", (*walker).name);
            fprintf(myfile, "\nGrade for task 1: %g", (*walker).task1);
            fprintf(myfile, "\nGrade for task 2: %g", (*walker).task2);
            fprintf(myfile, "\nGrade for task 3: %g", (*walker).task3);
            fprintf(myfile, "\nSum of all  grades: %g", (*walker).sumOfPoints);
        }
        ++walker;
    }
}
