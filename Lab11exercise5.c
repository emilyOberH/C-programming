#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void display(FILE *);
void caps(FILE *, FILE *);

int main(){
    char name[50];
    char txt[5]=".txt";
    printf("\nName file as: ");
    scanf("%s", name);
    strcat(name, txt);

    FILE *myfile = fopen("Alice_Merton_Song.txt", "r");
    display(myfile);
    fclose(myfile);

    printf("\nFile formatted to be all capital letters and saved under %s. ", name);
    FILE *old = fopen("Alice_Merton_Song.txt", "r");
    FILE *mod = fopen(name, "w");
    caps(old, mod);
    fclose(mod);
    fclose(old);

    printf("\nContents of modified file: ");
    FILE *myfileD = fopen(name, "r");
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

void caps(FILE *old, FILE *mod){
    char c;
    while((c=getc(old))!=EOF){
        if(isalpha(c)){
            fprintf(mod, "%c", toupper(c));
        }else{
            fprintf(mod, "%c", c);
        }
    }
}
