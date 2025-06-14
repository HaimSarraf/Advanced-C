#include <stdio.h>
#include <math.h>

int convertDecimalToBinary()
{
    int decimalNumber;

    int binaryNumber;

    printf("Please Enter a Number : ");

    scanf("%d", &decimalNumber);

    while (decimalNumber > 127 || decimalNumber< -128) {
        printf("Enter a Number Between -128 and +127");
    
        break ;
    }

    if(decimalNumber / 127 == 1){
        binaryNumber = 01111111;
    } else if(decimalNumber / 64);

}