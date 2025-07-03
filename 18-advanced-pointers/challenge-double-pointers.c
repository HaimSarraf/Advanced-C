#include <stdio.h>

int main()
{
    int num = 123;
    int *singlePointer = NULL;
    int **doublePointer = NULL;

    singlePointer = &num;
    doublePointer = &singlePointer;


    printf("The value of num is                                    : %d\n" , num);
    printf("The value of num using singlePointer is                : %d\n" , *singlePointer);
    printf("The value of num using doublePointer is                : %d\n\n" , **doublePointer);

    printf("Address of num is                                      : %p\n", &num);
    printf("Address of num using singlePointer is                  : %p\n", singlePointer);
    printf("Address of num using doublePointer is                  : %p\n\n", *doublePointer);

    printf("Value of Pointer singlePointer is                      : %p\n", singlePointer);
    printf("Value of Pointer singlePointer using doublePointer is  : %p\n\n", *doublePointer);
    printf("Address of Pointer singlePointer is                    : %p\n" , &singlePointer);
    printf("Address of Pointer singlePointer using doublePointer is: %p\n\n" , doublePointer);

    printf(" Value  of Pointer doublePointer is                    : %p\n", doublePointer);
    printf("Address of Pointer doublePointer is                    : %p\n", &doublePointer);
    
    return 0;
}
