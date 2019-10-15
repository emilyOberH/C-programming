#include <stdio.h>
#include <stdlib.h>


struct Students{
        char surname[50];
        char name[50];
        int year;
        int studyYear;
        int ECTS;
        double average;
};

void storeArray(FILE *, int, struct Students *, int);

int main(){
    int n;
    printf("\nRead at most how many students? ");
    scanf("%d", &n);
    FILE *binfile = fopen("students.bin", "rb");
    struct Students *A = (struct Students*)malloc(n*sizeof(struct Students));
    if(binfile){
        for(int i=1; i<4; ++i){
            printf("\nStudents from year %d contained in array:\n", i);
            storeArray(binfile, n, A, i);
        }

    }else{
        printf("\nFile could not be opened.");
        exit(1);
    }

    return 0;
}

void storeArray(FILE *file, int n, struct Students *A, int grade){
    struct Students *walker = A;

    rewind(file);
    struct Students tmp;
    int counter = 1;
    while(counter<=n){
        fread(&tmp, sizeof(tmp), 1, file);
        *walker = tmp;
        if(tmp.studyYear==grade){
            printf("\nSurname: %s ", tmp.surname);
            printf("\nName: %s ", tmp.name);
            printf("\nBorn: %d ", tmp.year);
            printf("\nYear: %d ", tmp.studyYear);
            printf("\nECTS: %d ", tmp.ECTS);
            printf("\nAverage: %lf ", tmp.average);
            printf("\n");
        }
        ++counter;
        ++walker;

    }
}
