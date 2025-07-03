#include <stdio.h>

int main()
{
    int num = 123;
    int *ptr = &num;
    int **pptr = &ptr;


    printf("The value of num is            : %d\n" , num);
    printf("The value of num using ptr is  : %d\n" , *ptr);
    printf("The value of num using pptr is : %d\n\n" , **pptr);

    printf("Address of num is              : %p\n", &num);
    printf("Address of num using ptr is    : %p\n", ptr);
    printf("Address of num using pptr is   : %p\n", *pptr);

    printf("Value of Pointer ptr is        : %p\n", &ptr);
    printf("Value of Pointer pptr is       : %p\n", pptr);

    return 0;
}