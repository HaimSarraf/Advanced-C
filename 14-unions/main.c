#include <stdio.h>

/*

struct owner {
    char socsecurity[12];
};

struct leasecompany {
    char name[40];
    char headoffice[40];
};

struct car_data {
    char make[15];
    int status; //? 0 = owned , 1 = leased;
    union { //? this is annanymous union
        struct owner owncar;
        struct leasecompany leasecar;
    };
};

struct {
    char *name;
    enum symbolType type;
    union {
        int   i;
        float f;
        char  c;
    } data; //? each data can be just int OR float OR char !!!
} table [entries] ;

*/

union mixed {
  char c;
  float f;
  int i;
};

union number {
  int x;
  double y;
};

void printVariables();
void printNumbers();
void foo(union number n);
void printPointer();

int main() {
  printf("Some simple examples of unions\n\n");
  // printVariables();
  // printNumbers();
  printPointer();


  return 0;
}

void printVariables() {
  union mixed x;
  union mixed y;
  union mixed z;

  x.c = 'j';
  y.f = 72.6345;
  z.i = 100;

  printf("Character = %c\n", x.c);
  printf("Float = %.4f\n", y.f);
  printf("Integer = %d\n", z.c);
}

void printNumbers() {
  //! each union can just be assigned only 1 value
  //!  for all its elements at a time

  union number value; //? define union variable

  value.x = 100; //? put an integer into the union

  // union number num = {.x = 20}; ===  union number num = {20};
  //? only can be initialized for its first element

  printf("value of integer x : %d\n", value.x);
  printf("value of double y : %f\n", value.y);

  value.y = 100.0; //? put an double into union

  printf("value of integer x : %d\n", value.x);
  printf("value of double y : %f\n", value.y);
}

void foo(union number n)
{
    union number x = n;
}

void printPointer(){

  union number x;
  union number *y = &x;

  y->y = 100.0;
  printf("value of integer x : %d\n", y->x);
  printf("value of double y : %f\n", y->y);
}