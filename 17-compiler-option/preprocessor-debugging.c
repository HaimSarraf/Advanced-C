#include <stdio.h>

#define DEBUG

//! if comment the define above,
//! can run this in terminal :
//! gcc -D DEBUG x.c

int process(int i, int j, int k);

int main() {
  int i, j, k, nread;

  nread = scanf("%d %d %d", &i, &j, &k);

#ifdef DEBUG
  fprintf(stderr, "Number of integers read : %i\n", nread);
  fprintf(stderr, "i = %i, j = %i, k = %i\n", i, j, k);
#endif

  printf("%d\n", process(i, j, k));

  return 0;
}

int process(int i, int j, int k) { return i + j + k; }