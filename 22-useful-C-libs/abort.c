#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("someFile.txt", "r");

    if(fp == NULL){
        printf("Going to abort the program\n");
        abort();
    }

    printf("Going to close the file\n");
    fclose(fp);

    return 0;
}