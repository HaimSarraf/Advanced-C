#include <stdio.h>

int sum(int n);
int greatestCommonDenominator(int a, int b);
char * reverseString(char * string);


int main() {

  //! ---------- 1 ----------

  int n;

  printf("Enter a positive integer: ");

  scanf("%d", &n);

  printf("The last input number of the range starting from 1 : %d\n", n);

  printf("The sum of the range is : %d\n", sum(n));

  //! ---------- 2 ----------

  printf("\n\n\n\n\n\n");

  int num1, num2;

  printf("Input 1st number : ");
  scanf("%d", &num1);
  printf("Input 2nd number : ");
  scanf("%d", &num2);
  printf("The greatest common denominator is : %d\n",
         greatestCommonDenominator(num1, num2));

  //! ---------- 3 ----------

  char str[100];
  char *rev = NULL;

  printf("Enter a string: ");
  scanf("%s", str);

  printf("The Original string is: %s\n", str);
  rev = reverseString(str);
  printf("Reversed string is: %s\n", rev);

  return 0;
}

int sum(int n) {
  int result = 0;

  if (n == 1) {

    return 1;

  } else {

    result = n + sum(n - 1);
  }

  return result;
}

int greatestCommonDenominator(int a, int b) {

  while (a != b) {
    if (a > b) {
      return greatestCommonDenominator(a - b, b);
    } else {
      return greatestCommonDenominator(a, b - a);
    }
  }

  return a;
}

char * reverseString(char * string) {
    static int i = 0;
    static char reversed[100];
    if (*string) {
        reverseString(string + 1);
        reversed[i++] = *string;
    }
    return reversed;
}