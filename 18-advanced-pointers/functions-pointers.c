#include <stdio.h>

void func_1(int);
void func_2(int);

typedef void FuncType(int);

int main() {
  //! --- 1 ---
  FuncType *func_ptr = NULL;

  func_ptr = func_1;

  (*func_ptr)(100);

  func_ptr = func_2;

  (*func_ptr)(200);

  return 0;
}

void func_1(int testArg) { 
    printf("func_1 got an argument of %d\n", testArg); 
}
void func_2(int testArg) { 
    printf("func_2 got an argument of %d\n", testArg); 
}