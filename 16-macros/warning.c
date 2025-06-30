#include <stdio.h>

#define Warning(...) fprintf(stderr, __VA_ARGS__)

#define MAX(a,b) (a>b ?  a :  b)

int main()
{
    Warning("%s : this program is here\n", "Shadow");

    printf("The MAX of 34 , 25 is %d\n", MAX(25, 34));

    return 0;
}