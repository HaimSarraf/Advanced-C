#include <stdio.h>

int main()
{
    int num , position , newNum, bitStatus;

    printf("Enter any Number : ");
    scanf("%d" , &num);

    printf("Enter 'n'th bit to check and set in 32 bits (0-31) : ");
    scanf("%d",&position);

    //? right shift num, position times and perform bitwise AND with 1
    bitStatus = (num >> position) & 1 ;
    printf("The %d bit is set to %d\n", position, bitStatus);

    //? left shift 1, n times and perform bitwise OR with num
    newNum = (1 << position) | num;
    printf("\nBit set succeccfully.\n\n");
    
    printf("Number before setting %d bit : %d (in decimal)\n", position,num);
    printf("Number  after setting %d bit : %d (in decimal)\n", position,newNum);

    return 0;
}

// working with a complete manuel bitmask is harder

