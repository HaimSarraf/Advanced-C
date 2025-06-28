#include <stdio.h>
// #include <stdlib.h>

int factorial(int n);
void up_and_down(int);

int main() {

  int n;

  printf("Please Enter a Positive Number :");

  scanf("%d", &n);

  printf("The Factorial of %d is %d\n", n, factorial(n));

  //! --------------------------------------------------

  printf("\n\n\n\n");

  up_and_down(n);

  return 0;
}

int factorial(int n) {
  int result = 0;

  if (n == 0) {
    result = 1;
  } else {
    result = n * factorial(n - 1);
  }

  return result;
}


void up_and_down(int n)
{
    printf("Level %d : n location  %p\n", n , &n); //! --1--
    
    if (n<4) {
        up_and_down(n+1);
    }
    
    printf("Level %d : n location  %p\n", n , &n); //! --2--
}