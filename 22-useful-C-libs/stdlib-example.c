#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//? double strtod(const char *str, char **str_end);
//? long int strtol(char const *s, char **end, int base);
//? double strtod(const char *str, char **str_end);

int main() {
  //! --- 1 ---
  /*
  char a[] = "365.47 7.05" , *end;
  float value1 = strtod(a, &end);
  float value2 = strtod(end, NULL);

  printf("Value = %f:%f\n", value1, value2);
  */

  //! --- 2 ---
  /*
  char str[30] = "20301000 This is test";
  char *ptr = NULL;
  long ret = 0;

  ret = strtol(str, &ptr, 10);
  printf("The number (unsigned long integer) is %ld\n", ret);
  printf("String part is [%s]\n", ptr);
  */

  //! --- 3 ---
  /*
  char a[] = "123.456xyz" , *end;
  double val = 0;

  val = strtod(a, &end);
  printf("value = %lf\n", val);
  */

  //! --- 4 ---
  /*
  char a[] = "25050004000";
  long value = atol(a);

  sprintf(a, "%ld", value);
  printf("value = %s\n", a);
  */

  //! --- 5 ---
  /*
  for (int i = 0; i<5; i++) {
      printf(" %d ", rand());
  }
  printf("\n");
  */

  //! --- 6 ---
  /*
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    printf(" %d ", rand());
  }
  printf("\n");
  */

  //! --- 7 ---
  /*
  char command[50];
  char list[50];

  strcpy(command, "ls -l");
  system(command);

  strcpy(list, "pwd");
  system(list);
  */

  //! --- 8 ---
    /*
    char *str;

    //? attempt to access environment variables using getenv()
    assert((str = getenv("HOME")) != NULL);
    printf("Value of \"HOME Environment Variable\" : %s\n", str);

    assert((str = getenv("PATH")) != NULL);
    printf("Value of \"PATH Environment Variable\" : %s\n", str);

    assert((str = getenv("LOGNAME")) != NULL);
    printf("Value of \"LOGNAME Environment Variable\" : %s\n", str);
    */

  //! --- 9 ---

  return 0;
}
