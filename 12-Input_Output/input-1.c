#include <stdio.h>

int main() {

  //? -1-

  // char ch = '\0';

  // ch = getc(stdin);

  // printf("read in character %c\n", ch);

  //? -2-

  /*
  int d= 0; //? should store its valus as int not CHAR!
  //? if store d as character, the result will be
  //? unpredictable due to sign extensions on systems

  while ((d = getchar()) != EOF) {

  printf("read in character to getchar : %c\n", d);

  }

  //? hit ctrl+d to send the signal,
  //? transmit it to the output and
  //? it's going to simulate the END OF FILE.

  */

  //? -3-

  /*
  FILE *fp = NULL;

  char c = '\0';

  fp = fopen("myFile.c", "r"); // opening an existing file

  if (fp == NULL) {
    printf("Could not open file myFile.c\n");

    return 1;
  }

  printf("Reading the file myFile.c\n");

  while (1) {
    c = fgetc(fp); // reading the file

    if (c == EOF) {
      break;
    }

    printf("%c", c);
  }

  printf("Closing the file test.c");
  fclose(fp); // closing the file
 
  */

  //? -4-

  char ch = 0;

  while (isspace(ch = (char)getchar())); // Read as long as there are spaces
  ungetc(ch, stdin);           // Put back the nonspace character
  //? if we uncomment ungetc(ch,stdin), then
  //? the result in terminal won't show the nonspace character,
  //? because we didn't put it back to stdin .

  printf("char is %c\n", getchar());

  return 0;
}