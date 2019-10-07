#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void startingLetter (FILE *, FILE *, char);
void display(FILE *);

int main(){
    FILE *myfile = fopen("words.txt", "r");
    display(myfile);
    fclose(myfile);

    char given;
    printf("\nEnter letter: ");
    scanf("%c", &given);

    FILE *myfileB = fopen("words.txt", "r");
    FILE *myfileC = fopen("words_starting_with.txt", "w");
    startingLetter(myfileB, myfileC, given);
    fclose(myfileC);
    fclose(myfileB);

    FILE *myfileD = fopen("words_starting_with.txt", "r");
    printf("\nContents of new file (words only starting with %c):\n", given);
    display(myfileD);
    fclose(myfileD);
    return 0;
}

void display(FILE *file){
    char c;
    while((c=getc(file))!=EOF){
        printf("%c", c);
    }
}

void startingLetter (FILE *file, FILE *destination, char s){
    char c;
    int begin = 1;
    int print = 1;
    while((c=getc(file))!=EOF){
        if(isspace(c)||c=='\n'){
            begin = 1;
        }
        if(isalpha(c)&&begin==1){
            if(c==s){
                print=1;
            }else{
                print=0;
            }
            begin = 0;
        }
        if(print==1){
            fprintf(destination, "%c", c);
        }
    }
}
