#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void replace(FILE *, FILE *, char);
void display(FILE *);

int main(){
    FILE *myfile = fopen("words.txt", "r");
    display(myfile);
    fclose(myfile);

    char given = '*';

    FILE *myfileB = fopen("words.txt", "r");
    FILE *myfileC = fopen("asterix.txt", "w");
    replace(myfileB, myfileC, given);
    fclose(myfileC);
    fclose(myfileB);

    FILE *myfileD = fopen("asterix.txt", "r");
    printf("\n\nContents of new file (lines only containing *, first letter of line or last letter of line):\n", given);
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

void  replace(FILE *file, FILE *destination, char s){
    char c;
    char buffer[50];
    char begin;
    char end;
    int len;
    while(1){
        for(int i=0; i<50; ++i){
            buffer[i] = '\0';
        }
        int r = fscanf(file, "%s\n", buffer);
        if(r==EOF){
            break;
        }
        begin = buffer[0];
        for(int i=0; i<sizeof(buffer); ++i){
            if(buffer[i]=='\0'){
                break;
            }
            len = i;
        }
        end = buffer[len];

        for(int i=0; i<sizeof(buffer); ++i){
            if((buffer[i]!=begin&&buffer[i]!=end)&&buffer[i]!='\0'){
                fprintf(destination, "%c", '*');
            }else if(buffer[i]==begin||buffer[i]==end){
                fprintf(destination, "%c", buffer[i]);
            }
        }
        fprintf(destination, "%c", '\n');
    }
}

