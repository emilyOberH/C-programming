#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double findGlobalAverage(FILE *);

int main(){
    FILE *myfile = fopen("averages.txt", "r");

    printf("\n\nGlobal average is: %g\n", findGlobalAverage(myfile));

    fclose(myfile);
    return 0;
}


double findGlobalAverage(FILE *myfile){
    rewind(myfile);

    double sum = 0.0;
    int counter = 0;
    double avg;
    int id;

    while(1){
        int r = fscanf(myfile,"%d;%lf\n", &id, &avg);
        if(r==EOF){
            break;
        }
        printf("\nStudent with ID: %d has an average of %g", id, avg);
        sum+=avg;
        ++counter;
    }

    return sum/counter;
}
