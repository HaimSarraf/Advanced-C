#include <malloc.h>
#include <stdio.h>

void allocateMemory(int *ptr);
void allocateMemoryUsingDoublePointer(int **ptr);

int main() { 
    
    int *ptr = NULL;
    
    /*
    allocateMemory(ptr);
    *ptr = 10;
    printf("%d\n", *ptr);
    //? free up the memory
    free(ptr);
    //! return error, cause it's a copy !
    */

    allocateMemoryUsingDoublePointer(&ptr);
    *ptr = 20;
    printf("%d\n", *ptr);
    free(ptr);

    return 0; 
}

void allocateMemory(int *ptr) { 
    ptr = (int *)malloc(sizeof(int)); 
}

void allocateMemoryUsingDoublePointer(int **ptr)
{
    *ptr = (int *)malloc(sizeof(int));
}
