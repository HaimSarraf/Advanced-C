#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//? this last 3 lines below, are for //! --- 9 ---
#define SIZE 10
void show_array(const int ar[], int n);
static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");

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
  /*
  int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target[SIZE];
  double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
  puts("memcpy() used:");
  puts("values (original data): ");
  show_array(values, SIZE);
  memcpy(target, values, SIZE * sizeof(int));
  puts("target (copy of values) : ");
  show_array(target, SIZE);

  puts("Using memmove() with overlapping ranges: ");
  memmove(values + 2, values, 5 * sizeof(int));
  puts("values -- elements 0-5 copied to 2-7: ");
  show_array(values, SIZE);

  puts("\nUsing memcpy() to copy double to int: ");
  memcpy(target, curious, (SIZE / 2) * sizeof(double));
  puts("target -- 5 DOUBLES into 10 INT positions :");
  show_array(target, SIZE / 2);
  show_array(target + 5, SIZE / 2);
  */

  //! --- 10 ---
  /*
  char source[] = "hello world\n";
  char * target = strndup(source, 13);
  
  printf("%s", target);
  */

  return 0;
}

void show_array(const int ar[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", ar[i]);
  }

  putchar('\n');
}
