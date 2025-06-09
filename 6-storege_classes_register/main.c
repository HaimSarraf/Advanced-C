#include <stdio.h>

//? register int y = 10;
//! register variables only can be defined inside a block

int main() {
  register int x;

  //?  int *a = &x;
  //! this is false, cause
  //! the address of register variable is requested,
  //! and it's not located on RAM .


  //? register static int a;
  //! this returns an error in compilation-time,
  //! which said :
  //! multiple storage classes in declaration specifiers

  for (x = 0 ; x < 5; x++)
  {
    printf("%d\n", x);
  }

  return 1;

}