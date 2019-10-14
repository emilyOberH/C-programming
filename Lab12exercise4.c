#include <stdio.h>
#include <stdlib.h>

struct WTAplayers{
        char name[80];
        char surname[80];
        char nationality[40];
        int age;
        int no_of_points;
        int no_of_matches;
};

void readFromFile(int, FILE *, struct WTAplayers *);
void youngest(int, struct WTAplayers *);

int main(){
    int n;
    printf("\nRead at most how many players? ");
    scanf("%d", &n);
    struct WTAplayers *A = (struct WTAplayers*)malloc(n*sizeof(struct WTAplayers));

    FILE *players = fopen("WTAplayers.bin", "rb");
    if(players){
        readFromFile(n, players, A);
        youngest(n, A);
        fclose(players);
    }else{
        printf("File could not be opened.");
        exit(1);
    }

    free(A);
    return 0;
}

void readFromFile(int n, FILE *file, struct WTAplayers *A){
    struct WTAplayers *walker = A;

    rewind(file);
    struct WTAplayers tmp;
    int counter = 1;
    printf("\nContents of binary file:\n");
    while(counter<=n){
        fread(&tmp, sizeof(tmp), 1, file);
        *walker = tmp;
        printf("\nName: %s ", tmp.name);
        printf("\nSurname: %s ", tmp.surname);
        printf("\nNationality: %s ", tmp.nationality);
        printf("\nAge: %d ", tmp.age);
        printf("\nNo. of points: %d ", tmp.no_of_points);
        printf("\nNo. matches: %d ", tmp.no_of_matches);
        printf("\n");
        ++counter;
        ++walker;
    }
}

void youngest(int n, struct WTAplayers *A){
    struct WTAplayers *walker = A;
    struct WTAplayers *stopper = A+n;

    int age = ((*walker).age);
    printf("\nYoungest player:\n");
    while(walker<stopper){
        if(((*walker).age)<age){
           age = (*walker).age;
        }
        ++walker;
    }

    walker = A;
    while(walker<stopper){
        if(((*walker).age)==age){
            printf("\nName: %s ", (*walker).name);
            printf("\nSurname: %s ", (*walker).surname);
            printf("\nNationality: %s ", (*walker).nationality);
            printf("\nAge: %d ", (*walker).age);
            printf("\nNo. of points: %d ", (*walker).no_of_points);
            printf("\nNo. matches: %d ", (*walker).no_of_matches);
            printf("\n");
        }
        ++walker;
    }
}
