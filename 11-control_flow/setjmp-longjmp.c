#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void myFunction(void);

int main()
{
    //! ---1---
    /*
    int i = setjmp(buf);
    
    printf("i=%d\n",i);
    
    if (i != 0) {
        exit(0);
    }
    
    longjmp(buf, 42);
    
    printf("Does this line get printed?\n");
    */
    
    //! ---2---
    if (setjmp(buf)) {
        printf("back in main\n");
    } else {
    
        printf("first time throuth\n");

        myFunction();
    }


    return 0;
}

void myFunction(void)
{
    printf("in myFunction()\n");

    // longjmp(buf, 1);

    /* NOT REACHED */

    printf("you will never see this, because I longjmp'd \n");
}

// switch (setjmp(jbuf)) {
//     case 0 :
//         apple = *sespecious;
//         break;
//     case 1 :
//         printf("suspecious is indeed a bad pointer\n");
//         break;
//     default :
//         die("unexpected value returned by setjmp\n");
// }

