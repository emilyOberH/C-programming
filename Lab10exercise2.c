#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void appendIntegers(FILE *, int);
double readIntegers(FILE *);
double copy(FILE *, FILE *, double);

int main(){
    int n;
    printf("\nAppend how many integers? ");
    scanf("%d", &n);

    FILE *myfile = fopen("numbers.txt", "a");
    appendIntegers(myfile, n);
    fclose(myfile);

    FILE *myfileB = fopen("numbers.txt", "r");
    printf("\nContent of file:\n");
    double avg = readIntegers(myfileB);
    printf("\n");
    fclose(myfileB);

    FILE *myfileD = fopen("numbers.txt", "r");
    FILE *myfileC = fopen("greater_than_average.txt", "w");
    copy(myfileB, myfileC, avg);
    fclose(myfileD);
    fclose(myfileC);
    return 0;
}

void appendIntegers(FILE *myfile, int n){
    for(int i=0; i<n; ++i){
        int num;
        printf("\nEnter integer %d out of %d: ", i+1, n);
        fflush(stdin);
        scanf("%d", &num);
        fprintf(myfile, "%d ", num);
    }
}

double readIntegers(FILE *myfile){
    int sum = 0;
    double counter = 0.0;
    char c;
    if(myfile){
        char buffer[50];
        for(int i=0; i<50; ++i){
            buffer[i]='\0';
        }
        while((c=getc(myfile))!=EOF){
            printf("%c", c);
            int len = strlen(buffer);
            if(isdigit(c)){
                buffer[len]=c;
            }
            if(!isdigit(c)&&len>0){
                ++counter;
                int num = atoi(buffer);
                sum+=num;
                for(int i=0; i<len; ++i){
                    buffer[i]='\0';
                }
            }
        }
    }
    printf("\n\nAverage is: %g", sum/counter);
    return sum/counter;
}


double copy(FILE *myfile, FILE *myfileC, double avg){
    int sum = 0;
    double counter = 0.0;
    char c;
    if(myfile){
        char buffer[50];
        for(int i=0; i<50; ++i){
            buffer[i]='\0';
        }
        while((c=getc(myfile))!=EOF){
            int len = strlen(buffer);
            if(isdigit(c)){
                buffer[len]=c;
            }
            if(!isdigit(c)&&len>0){
                ++counter;
                int num = atoi(buffer);
                if(num>avg){
                    fprintf(myfileC, "%d\t", num);
                }
                sum+=num;
                for(int i=0; i<len; ++i){
                    buffer[i]='\0';
                }
            }
        }
    }
    printf("\n\nAll numbers greater than %g have been copied to file \"greater_than_average.txt\"\n", avg);
    return sum/counter;
}
