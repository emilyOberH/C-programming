#include <stdio.h>
#include <stdlib.h>

struct Person{
    char name[50];
    int age;
};

void enterData(struct Person *, int);
void printData(struct Person *, int, FILE *);
void readFromFile(struct Person *, int, FILE *);

int main(){
    int n;
    printf("\nHow many people? ");
    scanf("%d", &n);

    FILE *myfile = fopen("list_of_People.bin", "wb");
    if(myfile){
        struct Person *A = (struct Person *)malloc(n*sizeof(struct Person));
        enterData(A, n);
        printData(A, n, myfile);
        fclose(myfile);

        FILE *readFile = fopen("list_of_People.bin", "rb");
        if(readFile){
            readFromFile(A, n,myfile);
            fclose(readFile);
        }else{
            printf("\nCould not open file.");
            free(A);
            exit(1);
        }
        free(A);
    }else{
        printf("\nCould not open file.");
        exit(1);
    }
    return 0;
}

void enterData(struct Person *A, int n){
    struct Person *walker = A;
    struct Person *stopper = A+n;
    while(walker<stopper){
        printf("\nEnter age of participant: ");
        scanf("%d", &(walker->age));
        printf("\nEnter name of participant: ");
        fflush(stdin);
        scanf("%[^\n]", (walker->name));
        ++walker;
    }
}

void printData(struct Person *A, int n, FILE *file){
    struct Person *walker = A;
    struct Person *stopper = A+n;
    while(walker<stopper){
        fwrite(&(*walker), sizeof(*walker), 1, file);
        ++walker;
    }
}

void readFromFile(struct Person *A, int n, FILE *file){
    rewind(file);
    struct Person tmp;
    printf("\nContents of binary file:\n");
    while(fread(&tmp, sizeof(tmp), 1, file)){
        printf("%d, ", tmp.age);
        printf("%s\n", tmp.name);
    }
}
