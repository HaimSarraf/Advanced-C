#include <stdio.h>

int initializer() { return 100; }

int fun() {
  static int count = 0;

  static int initialized;

  initialized = initializer();

  static int hasValue = 50;

  static int noValue;

  noValue = 51;

  int localVar = 0;

  printf("automatic = %d \t static = %d\n", localVar, count);

  printf("hasValue = %d \t noValue = %d\n", hasValue, noValue);

  printf("initialized = %d\n", initialized);

  count++;
  localVar++;
  hasValue++;
  noValue++;
  initialized++;

  return count;
}

int main() {

  //! the static variable
  //! doesn't redecalre each time it's called,
  //! it just reassigned
  //! so, in this example, it holds 1 and then add 1 to it


  //? if the static variable doesn't assign directly,
  //? the default 0 will be push to it.
  //? so everytime it's called, will be initialized 0 by the compiler;

  for (int i = 0; i < 5; i++) {
    fun();
  }

  return 0;
}