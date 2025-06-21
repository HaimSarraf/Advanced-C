#include <stdio.h>

int main() {

  //! ---1---
  // char ch = '\0';
  // FILE *fp = NULL;

  // if (fp = fopen("someFile.c", "rw")) {

  //     ch = getc(fp);

  //     while (ch != EOF) {
  //         putc(ch, fp);
  //         ch = getc(fp);
  //     }

  //     fclose(fp);

  // }

  //! ---2---
  // char ch = 'd';  // it must be a valid character

  // putc(ch, stdout);

  //! ---3---

  //   char string[] = "Hello World.\n I am still alive";

  //   int i = 0;

  //   while (string[i] != '\0') {

  //     if (string[i] != '\n') {
  //       putchar(string[i]);
  //     } else {
  //       putchar('*'); // put an * instead of going to new line.
  //     }
  //     ++i;
  //   }
  //   printf("\n");

  //! ---4---

    // int ch = 0;

    // while((ch = getchar()) != EOF )
    // {
    //   putchar(ch);
    // }

    // // ungetc() returns EOF previously read back to stdin
    // ungetc(ch,stdin);

    // printf("Thank You\n");

  //! ---5---

  FILE *pFile = NULL;

  char c = '\0';

  pFile = fopen("myFile.txt", "w");

  if (pFile != NULL) {
    for (c= 'A'; c <= 'Z'; c++) {
        // fputc(c, pFile);
        fputc(c, stdout);

        printf(" ");
    }
    fclose(pFile);
  }
  printf("\n");


  return 1;
}