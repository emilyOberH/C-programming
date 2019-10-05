#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void display(FILE *);
void copyIf(FILE *, FILE *, char [50]);

int main(){
    char name[50];
    char txt[5]=".txt";
    char search[50];
    FILE *myfile = fopen("sentences.txt", "r");
    display(myfile);
    fclose(myfile);

    printf("\nName file as: ");
    scanf("%s", name);
    strcat(name, txt);

    printf("\nCopy only lines with containing the following string into new file: ");
    scanf("%s", search);
    FILE *old = fopen("sentences.txt", "r");
    FILE *mod = fopen(name, "w");
    copyIf(old, mod, search);
    fclose(mod);
    fclose(old);

    FILE *modB = fopen(name, "r");
    printf("\nContents of the new file:\n");
    display(modB);
    fclose(modB);
    printf("\n\n");
    return 0;
}

void display(FILE *file){
    char c;
    while((c=getc(file))!=EOF){
        printf("%c", c);
    }
}

void copyIf(FILE *old, FILE *mod, char search[50]){
    char buffer[100];
    while(1){
        int r = fscanf(old, "%[^\n]\n", buffer);

        if(r==EOF){
            break;
        }
        if(strstr(buffer, search)){
           fprintf(mod, "%s\n", buffer);
        }
    }
}

