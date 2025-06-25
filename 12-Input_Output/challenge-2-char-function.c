#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertCase(FILE *fptr, const char *path);

int main()
{
   //? File pointer to hold reference of input
   
   FILE *fptr = NULL;

   char path[100];

   printf("Enter path of source file : ");
   scanf("%s", path);

   fptr = fopen(path, "r");

   //? fopen() returns NULL if unable to open file in given mode.

   if (fptr == NULL) {
        //? unable to open file hence exit

        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privile");
        exit(EXIT_FAILURE);
   }

   convertCase(fptr, path);

   return 0;
}


void convertCase(FILE *fptr, const char *path)
{
    FILE *dest = NULL;

    char ch = '\0';

    //? Temporary file to store
    dest = fopen("temp.txt" , "w");

    //? if unable to create temp file
    if (dest == NULL) {
        printf("Unable to create temporary file.");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }

    //? Repeat till end of file
    while((ch = fgetc(fptr)) != EOF){
        //? if current character is uppercase ,
        //? then toggle it to lowercase and vice versa.
        if(isupper(ch)){
            ch = tolower(ch);
        } else if(islower(ch)){
            ch = toupper(ch);
        }

        //? print toggled characters to destination file
        fputc(ch,dest);
    }

    //? close all files to release resources
    fclose(fptr);
    fclose(dest);

    //? delete original source file
    remove(path);
 
    //? rename temporary file as original
    rename("temp.txt", path);

}

