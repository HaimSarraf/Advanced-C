#include <math.h>
#include <stdio.h>

int convertBinaryToDecimal(long long n);

int main() {
  long long n;
  int result = 0;

  printf("Enter a binary number : ");
  scanf("%lld", &n);

  result = convertBinaryToDecimal(n);

  printf("%lld in binary = %d in decimal\n", n, result);

  return 0;
}

int convertBinaryToDecimal(long long n) {
  int decinalNumber = 0, i = 0, reminder = 0;

  while (n != 0) {

    reminder = n % 10;

    n = n / 10;

    decinalNumber += reminder*pow(2, i);
    // decinalNumber += 1 << i ;

    i++;
  }

  return decinalNumber;
}


//! /////////////////////////////////////////////


// #include <stdio.h>
// #include <string.h>
// #include <math.h>

// int convertBinaryToDecimal(const char *binaryStr) {
//     int decimalNumber = 0;
//     int length = strlen(binaryStr);

//     for (int i = 0; i < length; i++) {
//         char bit = binaryStr[length - 1 - i]; // Start from right (LSB)

//         if (bit == '1') {
//             decimalNumber += pow(2, i);
//         } else if (bit != '0') {
//             // Invalid character
//             printf("Error: Invalid character '%c' in binary string.\n", bit);
//             return -1;
//         }
//     }

//     return decimalNumber;
// }


// int main() {
//     char binary[] = "1011";

//     int result = convertBinaryToDecimal(binary);

//     if (result != -1) {
//         printf("Decimal of %s is %d\n", binary, result);
//     }

//     return 0;
// }