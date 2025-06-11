#include <stdio.h>


void display(const int array[], int limit);
char  *strcat(char *restrict s1, const char * restrict s2);

int main(void)
{
    const double pi = 3.1415 ;

    const int days[12] = {1,2,3 };

    typedef const int zip ;

    const zip q ;

    //? //////////////////////////////////////

    const float *ptr_1; //! ptr_1 points to a constant float value

    float * const ptr_2; //* ptr_2 is a constant pointer

    const float * const ptr_3; //? both are constant

    float const *ptr_4; // same as const float *ptr_1

    //? //////////////////////////////////////



    return 0;
}


