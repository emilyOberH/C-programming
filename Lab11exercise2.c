#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void display(FILE *, bool (*) (char, char));
bool check (char, char);

int main(){
    FILE *myfile = fopen("sentences.txt", "r");

    display(myfile, check);

    fclose(myfile);
    return 0;
}

void display(FILE *file, bool (*func) (char, char)){
    char c;
    int lines = 0;
    int spaces = 0;
    int chars = 0;
    int letters = 0;
    while((c=getc(file))!=EOF){
        if(func(c, '\n')){
            ++lines;
        }
        if(func(c, ' ')){
            ++spaces;
        }
        if(func(c, c)){
            ++chars;
        }
        if(isalpha(c)){
            ++letters;
        }
        printf("%c", c);
    }
    printf("\nNumber of lines in file: %d", lines);
    printf("\nNumber of spaces in file: %d", spaces);
    printf("\nNumber of characters in file: %d", chars);
    printf("\nNumber of letters in file: %d\n", letters);
}

bool check(char c, char given){
    if(c==given){
        return true;
    }else{
        return false;
    }
}
