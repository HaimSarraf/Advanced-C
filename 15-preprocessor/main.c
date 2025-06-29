#include <stdio.h>

#define JUST_CHECKING
#define LIMIT 4
#define MYDEF 3

#pragma GCC poison printf
#pragma GCC warning "This is a warning"
#pragma GCC error "That's an error"
#pragma message "OK"

int main(void) {
  int i = 0;
  int total = 0;

  for (i = 1; i <= LIMIT; i++) {
    total += 2 * i * i + 1;

    #ifdef JUST_CHECKING
        printf("i=%d, running total = %d\n", i, total);
    #endif
  }

  printf("Grand Total = %d\n\n\n", total);

  #if MYDEF == 5 && LIMIT == 4
    printf("it is 5\n");
  #else
    printf("it is not 5\n");
  #endif    

  return 0;
}