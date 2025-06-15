#include <stdio.h>

long long convertDecimalToBinary(int n);

int main() {
  int num1 = 0, num2 = 0;

  long long b_num1 = 0, b_num2 = 0;

  int d_num1LeftShiftResult = 0;

  long long b_num1ComplementResult = 0;
  long long b_num2ComplementResult = 0;

  long long b_num1ANDnum2Result = 0;
  long long b_num1ORnum2Result = 0;

  long long b_num1EXORnum2Result = 0;
  long long b_num1LeftShiftResult = 0;

  printf("Enter an integer : ");
  scanf("%d", &num1);

  printf("Enter another integer : ");
  scanf("%d", &num2);

  b_num1 = convertDecimalToBinary(num1);
  b_num2 = convertDecimalToBinary(num2);

  b_num1ComplementResult = convertDecimalToBinary(~num1);
  b_num2ComplementResult = convertDecimalToBinary(~num2);

  b_num1ANDnum2Result = convertDecimalToBinary(num1 & num2);
  b_num1ORnum2Result = convertDecimalToBinary(num1 | num2);
  b_num1EXORnum2Result = convertDecimalToBinary(num1 ^ num2);

  d_num1LeftShiftResult = num1 << 2;
  b_num1LeftShiftResult = convertDecimalToBinary(d_num1LeftShiftResult);

  printf(
      "The result of applying the ~ operator on number %d (%lld) is : %lld \n",
      num1, b_num1, b_num1ComplementResult);
  printf(
      "The result of applying the ~ operator on number %d (%lld) is : %lld \n",
      num2, b_num2, b_num2ComplementResult);
  printf("The result of applying the & operator on number %d (%lld) and number "
         "%d (%lld) is : %lld \n",
         num1, b_num1, num2, b_num2, b_num1ANDnum2Result);
  printf("The result of applying the | operator on number %d (%lld) and number "
         "%d (%lld) is : %lld \n",
         num1, b_num1, num2, b_num2, b_num1ORnum2Result);
  printf("The result of applying the ^ operator on number %d (%lld) and number "
         "%d (%lld) is : %lld \n",
         num1, b_num1, num2, b_num2, b_num1EXORnum2Result);
  printf("The result of applying the << operator on number %d (%lld) is : (%d "
         ": numeric)  (%lld : binary) \n",
         num1, b_num1, d_num1LeftShiftResult, b_num1LeftShiftResult);

  return 0;
}

long long convertDecimalToBinary(int n) {
  long long binaryNum = 0;
  int reminder, i = 1;

  while (n != 0) {
    reminder = n % 2;

    n = n / 2;

    binaryNum += reminder * i;

    i = i * 10;
  }

  return binaryNum;
}