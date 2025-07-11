#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  char ch = '\0';
  int wrd = 1, charctr = 1;

  if (argc == 1) {
    fp = stdin;
  } else if (argc == 2) {

    if ((fp = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "Can't open %s\n", argv[1]);
    }

  } else {
    fprintf(stderr, "Usage : %s [filename]\n", argv[0]);
    exit(EXIT_FAILURE);
  }


  ch = getc(fp);


  while (ch != EOF) {
  
    if (ch == ' ' || ch == '\n') {
  
        wrd++;
  
    } else {
  
        charctr++;
    }

    ch = getc(fp);
  }

  printf("\n The number of words in this file : %d\n",   wrd-1);
  printf(" The number of characters in this file : %d\n\n",charctr-1);


  fclose(fp);

  return 0;
}