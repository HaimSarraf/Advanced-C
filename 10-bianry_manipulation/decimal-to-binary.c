#include <stdio.h>

long long convertDecimalToBinary(int n);

int main()
{
    int n = 0;

    long long result;

    printf("Enter a decimal number: ");

    scanf("%d", &n);

    result = convertDecimalToBinary(n);

    printf("%d in decimal = %lld in binary\n", n , result);

    return 0;

}

long long convertDecimalToBinary(int n)
{
    long long binaryNum =0 ;
    int reminder , i =1;

    while (n != 0) {
        reminder = n % 2;

        n = n / 2;

        binaryNum += reminder * i;

        i = i * 10;
    }

    return binaryNum;
}