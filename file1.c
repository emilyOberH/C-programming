#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *myfile;
    char filename[20]="numbers.txt";
    myfile=fopen(filename,"a");
    srand(time(NULL));
    int value=rand()%21-10;
    fprintf(myfile,"%d\n",value);
    fclose(myfile);
    return 0;
}
