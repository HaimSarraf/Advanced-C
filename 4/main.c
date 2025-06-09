#include <stdio.h>
//? here,
// we need to show the usage of
// external variables (one of
// storage-classes)

extern int count;

void print_count(void) { printf("The count is %d\n", count); }

int i = 5;

void foo(void);

int main() {
  printf("%d\n", i);

  foo();

  printf("%d\n", i);

  print_count();

  return 0;
}