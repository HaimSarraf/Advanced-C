#include <stdio.h>

int printPointersSize();
int printArrayPointersSize();

int main() {
  int i = 10;
  float f = 10.34;
  char ch = 'a';

  void *void_pointer = NULL;

  void_pointer = &i;
  printf("Value of i = %d\n", *(int *)void_pointer);
  //! ([type-of-data] *) : does the casting!
  //? first should cast the void pointer ,
  //? (int *) is casting it to integer => (int *)ptr ,
  //? then it should be dereferenced,
  //? * does this => *(int *)ptr

  //! NOTE : casting just has a temporary effect

  void_pointer = &f;
  printf("Value of f = %.2f\n", *(float *)void_pointer);

  void_pointer = &ch;
  printf("Value of ch = %c\n", *(char *)void_pointer);

  //? ------------------------------------------------\

  printf("\n\n\n\n\n");
  printPointersSize();

  printArrayPointersSize();
  return 0;
}

int printPointersSize() {
  void *void_pointer = NULL;
  int *int_pointer = NULL;
  float *float_pointer = NULL;
  char *char_pointer = NULL;

  printf("Size of   void pointer  = %d\n", (int)sizeof(int_pointer));
  printf("Size of integer pointer = %d\n", (int)sizeof(int_pointer));
  printf("Size of  float pointer  = %d\n", (int)sizeof(float_pointer));
  printf("Size of   char pointer  = %d\n", (int)sizeof(char_pointer));

  //! all the return-values of above lines are -- 8 --
  //! why ? because the -VOID-SIZE- is 8 .

  return 0;
}

int printArrayPointersSize()
{
    int aiData[3] = {10,20,30};

    void *pvData = &aiData[1];

    pvData += sizeof(int);

    printf("\n\n\n %d\n\n", *(int *)pvData);

    return 0;
}