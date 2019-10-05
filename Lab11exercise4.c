#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void display(FILE *file);

int main(){
    FILE *myfile = fopen("Alice_Merton_Song.txt", "r");
    display(myfile);
    fclose(myfile);
    return 0;
}


void display(FILE *file){
    char c;
    int last = 1;
    int lines = 0;
    int words = 0;
    int chars = 0;
    int letters = 0;
    while((c=getc(file))!=EOF){
        if(c=='\n'){
            --chars;
            last = 1;
            ++lines;
        }
        if(c==' '){
            last = 1;
        }
        if(isalpha(c)){
            if(last==1){
                ++words;
                last=0;
            }
            ++letters;
        }
        ++chars;
        printf("%c", c);
    }
    printf("\nNumber of lines in file: %d", lines);
    printf("\nNumber of words in file: %d", words);
    printf("\nNumber of characters in file: %d", chars);
    printf("\nNumber of letters in file: %d\n", letters);
}
