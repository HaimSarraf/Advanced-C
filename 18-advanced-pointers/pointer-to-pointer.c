#include <stdio.h>

int main() {
  int a = 10;

  int *p1 = NULL;
  int **p2 = NULL;

  p1 = &a;
  p2 = &p1;

  printf("Address of a  = %p\n", &a);
  printf("Address of p1 = %p\n", &p1);
  printf("Address of p2 = %p\n\n", &p2);

  //? below print statement will give the address of a
  printf("Value at the address stored by p2 = %p\n" , *p2);
  printf("Value at the address stored by p1 = %d\n\n" , *p1);
  printf("Value of **p2 = %d\n" , **p2); //? **p2 -> *(*p2)

  return 0;
}
