#include <stdio.h>


int main ()
{
    short int w1 = 25;
    short int w2 = 77;
    signed int x1 = 154;

    short int w3 = 0;
    short int w4 = 0;
    short int w5 = 0;
    short int w6 = 0;
    short int w7 = 0;
    signed int x2 = 0;

    w3 = w1 & w2;
    w4 = w1 | w2;
    w5 = w1 & -3;
    w6 = w1 ^ w2;
    w7 = ~w1;
    x2 = ~x1;

    printf("%hd\n" , w3);
    printf("%hd\n" , w4);
    printf("%hd\n" , w5);
    printf("%hd\n" , w6);
    printf("%hd\n" , w7);
    printf("%d\n" , x2);

    return 0;
}

//! & operator
/*
    w1  = 00011001
    w2  = 01001101
        -----------
    w3  = 00001001 (in decimal = 9)    
*/

//! | operator
/*
    w1  = 00011001
    w2  = 01001101
        -----------
    w4  = 01011101 (in decimal = 93)    
*/

//! ^ operator
/*
    //! 1

    //? every bit in w1, looks at the bit in w2
    //? if it's 0, it remains itself(0->0 and 1->1)
    //? if the bit in w2 is "1", 
    //? the bit of w1 becomes negative(0->1 and 1->0)

    w1  = 00011001
    w2  = 01001101
        -----------
    w6  = 01010100 (in decimal = 84)    

    //! 2
    //? to swap 2 variables we can say:
    x = w1;
    w1 = w2;
    w2 = x;

    //? but ^ makes it easier and we dont need the third variable:
    w1 ^= w2;
    w2 ^= w1;
    w1 ^= w2;
*/

//! ~ operator
/*
    w1 = 00011001
        ----------
    w7 = 11100110 (in decimal = -26)

    w7 = 1110  0110
    ->   0001  1001 + 1
    ->   0001  1010 = 16 + 8 + 2 = 26 but negative!



    //? 154 is bigger than 127 so it computed as 32bit!
    x1 = 154 = 1001 1010
    ~x1      = 0110 0101
    invert x1= 1001 1010
    add 1    = 1001 1011 = in decimal 155
    since its negative -> -155
*/
