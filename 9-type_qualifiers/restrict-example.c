#include <stddef.h>
#include <malloc.h>

void func(int n , float * restrict a1, const float * restrict a2)
{
    int i;

    for (i = 0; i< n; i++) {
        a1[i] += a2[i];
    }

    //! a1 & a2 can be assumed to refer to disjoint array objects.

    //? both a1 & a2 are restrict qualified .

}

int main(void)
{

    int n;

    int array[10];

    int * restrict restar = (int *) malloc(10 * sizeof(int));

    int *par = array; // it can not be qualified as restrict

    for( n =0 ; n< 10; n++){
        par[n] += 5;

        restar[n] += 5;

        array[n] *= 2;

        par[n] +=3 ;

        restar[n] += 3;
    }

    restar[n] += 8;

    // par[n] += 8; // unComment this to catch error in compilation time


    void * memcpy(void * restrict s1, const void * restrict s2, size_t n);
    //! memcopy requires that there be no overlap
    //! between the two locations : s1 , s2

    void  * memmove(void * s1, void const * s2, size_t n);
    //! does not need the above requirement

    return 0; 

}