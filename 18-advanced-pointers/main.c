#include <malloc.h>
#include <stdio.h>
#include <string.h>

void foo(int *ptr);
void hoo(int *ptr);
void goo(int **ptr);
void joo(char *ptr);
void joo_2(char **ptr);

int main() {
  int *ptr = NULL;
  char *ptr_2 = NULL; //* to use in joo()

  ptr = (int *)malloc(sizeof(int));

  *ptr = 10;

  foo(ptr);
  printf("in foo %d\n\n\n", *ptr);
  //? why we use p-to-p ?
  //? because as you see, in this example,
  //? the second line of function "foo()" ,
  //? doesn't modify the ptr.
  //? that means "ptr = &a" is NOT working !!!

  hoo(ptr);
  printf("in hoo %d\n\n\n", *ptr);
  //? as you can see, by using double pointers,
  //? we can easily modify the ptr now .

  // goo(&ptr);
  // printf("in goo %d\n\n\n" , *ptr); //* returns 5

  joo(ptr_2);
  printf("in joo %s\n", ptr_2);
  free(ptr_2);
  //? after we run the program, it crashes.
  //? why? because we are allocating memory to a copy,
  //? this is the point we should use p-o-p !
  //* see the details here :
  //* we define a pointer called ptr,
  //* ptr = 0xffffff ;
  //* this address, pointing to a value,
  //* 0xffffff = 6 ; (for example)
  //* we also have the address of ptr, 0xjjjjjj
  //* &ptr = 0xjjjjjj ;
  //* if we make a copy of this pointer -> ptr_1,
  //* we will have :
  //* a new address : &ptr_1 = 0xkkkkkk ;
  //* ptr_1 = 0xffffff ; (still pointing to the same address)
  //* so if we try to allocate memory to "ptr's address",
  //* we are allocating memory to 0xkkkkkk not 0xjjjjjj
  //* we are allocating memory to  &ptr_1  not  &ptr .
  //* so we can't change the value of what ptr_1 is for a malloc,
  //* inside a function, unless we pass-in a double-pointer,
  //* because we can't allocate memory to a copy of a pointer.

  joo_2(&ptr_2);
  printf("after use pointer-to-pointer :\n");
  printf("in joo_2 %s\n",ptr_2); //? does Not need dereference cause it is string
  free(ptr_2);

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
void goo(int **ptr) {
  int a = 5;
  *ptr = &a;
}
void joo(char *ptr) {
  ptr = malloc(255);
  strcpy(ptr, "hello world\n");
}
//? to solve its problem, redefine joo()
void joo_2(char **ptr) {
  *ptr = malloc(255);
  strcpy(*ptr, "hello world\n");
}