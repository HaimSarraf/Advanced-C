#include <stdio.h>

int fun() {
  static int count = 0;

  count++;

  return count;
}

int main() {
  printf("%d\n", fun());

  //! the static variable
  //! doesn't redecalre each time it's called,
  //!  it just reassigned
  //! so, in this example, it holds 1 and then add 1 to it
  printf("%d\n", fun());

  return 0;
}