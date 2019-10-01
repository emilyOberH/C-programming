#include <stdio.h>

int main()
{
    FILE *myfile;
    char filename[20]="story.txt";
    myfile=fopen(filename,"a");
    printf("Type a sentence: ");
    char buffer[80];
    fgets(buffer,sizeof(buffer),stdin);
    fputs(buffer,myfile);
    fclose(myfile);
    return 0;
}
