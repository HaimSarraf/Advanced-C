#include <stdio.h>
#include <assert.h>
#include <limits.h>

static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
//? char-bit == 8 !

int main(void)
{
    //! --- 1 ---
    /*
    int y = 5;
    
    for (int x=0; x<20; x++) {
        printf("x = %d y = %d\n", x,y);
        assert(x < y);
    }
    */

    //! --- 2 ---
    puts("Char is 16 bits.\n");

    return 0;
}