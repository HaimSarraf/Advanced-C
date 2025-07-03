#include <malloc.h>
#include <stdio.h>

void foo(int *ptr);
void hoo(int *ptr);

int main() {
  int *ptr = NULL;

  ptr = (int *)malloc(sizeof(int));

  *ptr = 10;

  foo(ptr);
  printf("in foo %d\n\n\n" , *ptr);
  //? why we use p-to-p ?
  //? because as you see, in this example,
  //? the second line of function "foo()" ,
  //? doesn't modify the ptr.
  //? that means "ptr = &a" is NOT working !!!
  
  hoo(ptr);
  printf("in hoo %d\n\n\n" , *ptr);
  //? as you can see, by using double pointers,
  //? we can easily modify the ptr now .

  return 0;
}

void foo(int *ptr) {
  int a = 5;
  ptr = &a;
}
void hoo(int *ptr) {
  int a = 5;
  *ptr = a;
}