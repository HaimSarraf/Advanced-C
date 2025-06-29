#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main() {
  //! ---1---
  /*
  char buf[255];
  int ch = '\0';
  char *p = NULL;

  if (fgets(buf, sizeof(buf), stdin)) {
    p = strchr(buf, '\n');
    if (p) {
        *p = '\0';
    } else {
        while (((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin))
    ;
}
} else {
    //? fgets failed, handle error
}

printf("Our Buffer contains : %s\n", buf);
*/

  //! ---2---
  
  // char buffer[32];
  // char *b = buffer;
  // size_t bufsize = 32;
  // size_t characters;

  // /*
  // //? if we had : char *buffer = NULL;
  // //? we could define it as below :
  // buffer = (char *)malloc(bufsize * sizeof(char));
  
  // if(buffer == NULL){
  //   exit(1);
  // }

  // then the character sould be :
  // getline(&buffer, &bufsize, stdin);
  // */

  // printf("Type something : ");
  // characters = getline(&b, &bufsize, stdin);

  // printf("%zu characters were read.\n", characters);
  // printf("You typed : \n\t\t%s\n", buffer);
 
  //! ---3---

  //? int fputs(const char * buffer, FILE *filePointer)
  char string[40];
  strcpy(string, "Hello world !");
  puts(string);

  FILE *fp = NULL;
  fp = fopen("file.txt", "w");

  if(fp == NULL){
    exit(1);
  }

  fputs("Hello There, I hope this article will help !", fp);

  fclose(fp);

  //? the file.txt containing that sentence is now available in directory
  return 0;
}